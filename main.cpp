
// Project UID db1f506d06d84ab787baf250c265e24e


#include <iostream>
#include <string>
#include <map>
#include <set>
#include "csvstream.h"

#include  <cmath>
#include <limits>
using namespace std;

//office hours given 
set<string> unique_words(const string &str) {
  istringstream source(str);
  set<string> words;
  string word;
  while (source >> word) {
    words.insert(word);
  }
  return words;
}
//my True_classifer my warrior ^-^
class True_Classifer {

private:
    map<string, map<int, int>> posts;
    map<string,int> True_word_count; // map to store word counts
    map<string, map<string, int>> label_word_count; // map to store the number of times 
    //each word appears in each label
    
    map<string, map<string, int>>label_pair ; // map to store the number of times each 
    //word appears in each label
    map<string, map<string, double>> log_likelihood;//checking log_likihood
    map<string, double> log_prior;

    map<string,int >label_post_count; 
    int total_posts = 0;

    //have debug on and debug off
    bool debug_cond;
    void prior () {
        for (const auto& pair : label_post_count) {
            string label = pair.first;
            int true_count = pair.second;
            log_prior[label] = log(static_cast<double>(true_count) / total_posts);
        }
    }

    

public:

    // Constructor
    //bool debug_in
    True_Classifer(bool debug_in) : debug_cond(debug_in){
    }
    True_Classifer() {};
        //readining in training

    void trainer(char* argv[]) {
        if (debug_cond) {
            cout << "training data:" << endl;
        }
        
        string file;
        //readining in training
        csvstream csvin(argv[1]);
        map<string, string> row;
        while (csvin >> row) {
            string label = row["tag"];
            string content = row["content"];
            total_posts++;

            set<string>unique = unique_words(content);

            for (string word: unique) {
           
                True_word_count[word]++;
                label_word_count[label][word]++; 

            }
            if (debug_cond) {
                cout << "  label = " << row["tag"] << ", content = " 
                << row["content"] << endl;
            }
            
            label_post_count[label]++;//for each label seeing how many times post appears 
       
        }

    //if(debug)
//  cout << "trained on " << total_posts << " examples" << endl;
//   cout << "vocabulary size = " << True_word_count.size() << endl << endl;
//         }
        //volcuatary only print on debug if(debug)
        cout << "trained on " << total_posts << " examples" << endl;
        if (debug_cond) {
            cout << "vocabulary size = " << True_word_count.size() << endl << endl;
        }
        
    }
// Office hours say break it down
//Kami office hours tip
//breaking it down more conicse functions
//pasting code in each function making clean
//asking office hours tips
//calling everything at the end
//error checking
//we are gonna be arlight... 
    void prior_calculate() {
        //my calcuations go heere
        for (const auto& pair : label_post_count) {
            string label = pair.first;
            int true_count = pair.second;
            log_prior[label] = log(static_cast<double>(true_count) / total_posts);
        }
        //errpr checking
        if (debug_cond) {
            cout << "classes:" << endl;
        }
         
            for (const auto& label_count_pair : label_post_count) {
            string label = label_count_pair.first;
            int label_count = label_count_pair.second;
            //setting up our log_prior here make sure to clean

            double log_prior = log(static_cast<double>(label_count) / total_posts);
            log_prior += 0;
            //error checking protypieee 
            if (debug_cond) {
                std::cout << "  " << label << ", " << label_count <<
                 " examples, log-prior = " << log_prior << endl;

            }
            
        }
    }
        //Tyler officehours tips either functions or all in main 
        //I Make my Classifer more clean here
    void classifier_params() {
        if (debug_cond) {
            //my classifer cout statement starthere
            cout << "classifier parameters:" << endl;
        }
        double log_like;
        //Everything here pls work
        for(const auto& label_count_pair : label_post_count) {
            string label = label_count_pair.first;
            for (const auto& word_count_pair :label_word_count[label]) {
                string word = word_count_pair.first;
                int count = word_count_pair.second;
                if (count == 0) {
                    // Use when w does not occur in any posts with label 
                    //C in the training data
                log_like = log(1 / static_cast<double>(total_posts));

                } else {
                    log_like = log(count / static_cast<double> (label_post_count[label]));
                }

                // Output the results
                if(debug_cond) {
                    cout << "  " << label << ":" << word << ", count = " <<
                     count << ", log-likelihood = " << log_like << endl;

                }
                
            }
        }
    }
        //Test data function 
        //we learn that we need to break it down
        //we learn we need to make sure our function must be
        //in a function not straight ;-;
    void test_data (char *argv[]) {
    
        int correct_predictions = 0;
        string predicted_label;
////Everything above correct 

//Test Cout statement here
//if debug here()
//FINAL PART 2 Test

        cout << endl << "test data:" << endl;

        //readining in training
        int post_count = 0;
        csvstream csvin(argv[2]);
        map<string, string> row;

        //De orio likes goats :D
        //this is more clean using stackoverflow tips
        //blessed office hours helpers
        while (csvin >> row) 
        {
            post_count++;
            string content = row["content"];
            string label_correct = row["tag"];
            string label_predict;
            set <string> words = unique_words(content);
            std::map<string, double> log_prob;
            for (const auto& label_count_pair : label_post_count) {
                string label = label_count_pair.first;
                log_prob[label] = log(static_cast<double>(label_count_pair.second) / 
                total_posts);
                for (const auto& word : words) {
                    
                    if (label_word_count[label].find(word) != 
                    label_word_count[label].end()) 
                    {
                        int count = label_word_count[label][word];
                        log_prob[label] += log(count / 
                        (static_cast<double> (label_post_count[label])));    
                    } 
                    else if(True_word_count.find(word) != True_word_count.end()){
                        int count = True_word_count[word];
                        log_prob[label] += log( count / static_cast<double>(total_posts));
                        }
                    else{
                        log_prob[label] += log(1 / static_cast<double>(total_posts));
                        }
                }
            }
            double max_log_prob = -numeric_limits<double>::infinity();
            for (const auto &pair : log_prob) 
            {
                if (pair.second > max_log_prob) 
                {
                    predicted_label = pair.first;
                    max_log_prob = pair.second;
                }
            }
            //  results hopefully it works 
            //checks if the predicted_label is equal to the correct_label. 
            //it increments the correct_predictions variable by 1.
            if (predicted_label == label_correct) 
            {
                ++correct_predictions;
            }
            cout << "  correct = " << label_correct << ", predicted = " 
            << predicted_label 
            << ", log-probability score = " << log_prob[predicted_label] << endl;
            cout << "  content = " << content << endl << endl;
    
        }
        cout << "performance: " << correct_predictions << " / " 
             << post_count << " posts predicted correctly" << endl;
        
    }

    
    

    // the label with the highest log-probability score
    
};

//assert drebug_cond = false




// Logic might be iffy compared to MAIN

int main (int argc, char *argv[]) {
    cout.precision(3);
    
    //True_Classifer(argv
    //
    bool debug_cond = false;
    
///HOPE PLS THIS WORKS
//ASSERT DREAMMMS
    if (argc >= 3 && argc <=4) {
        string filename1 = string(argv[1]);
        string filename2 = string(argv[2]);
        try {
            csvstream csvin(filename1);
            map <string, string> row;
            csvin >> row;
        }
        //We blessed thank you
        //we error checkinggggg ;-; tips idk

        catch (const csvstream_exception &e) {
            cout << "Error opening file: " << filename1 << endl;
            return 2;
        }
        try {
            //Github DEoriooo
            csvstream csvin(filename2);
            map <string, string> row;
            csvin >> row;
        }
        
        catch (const csvstream_exception &e) {
            cout << "Error opening file: " << filename2 << endl;
            return 2;
        }
            //Argc error testing need to do tht
        if (argc == 4) {
            string debug_text = string(argv[3]);
            if (debug_text == "--debug") {
                debug_cond = true;
            }
            else {
                //Cout statements
                cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
                return 2;
            }
        }
    } else {

        //Love office hours help
        cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
        return 2;
    }
    
    True_Classifer tc(debug_cond);
    //callig my functions here 
    tc.trainer(argv);
    //prior calcutlarion
    tc.prior_calculate();
    //clasfier param is our cout
    tc.classifier_params();
    //building off test_data
    tc.test_data(argv);

    return 0;

} 
//PArker at office hours tips to clean up
// 1. Finish command line interface (reference P2 code on AG or locally)
// 2. Modify constructor to accept debug argument
// 3. Finish debug output within existing functions, add function to 
// print remaining output like "classes: ...", "classifier parameters: ..."