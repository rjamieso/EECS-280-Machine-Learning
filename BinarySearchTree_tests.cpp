// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"
#include <ostream>

using namespace std;
TEST(test_stub) {
    BinarySearchTree<int> b; 
    ASSERT_EQUAL(b.height(), 0u); 
}



TEST(empty_impl_test) {
  // Test case 1: empty_impl(nullptr) should return true
    BinarySearchTree<int> e3; 
  bool result1 = e3.empty();
  ASSERT_TRUE(result1);

  // Test case 2: empty_impl(new Node()) should return false
   //put in the values for the tree
    BinarySearchTree<int> e4; 
    //Node *test_node2 = new Node();
  bool result2 = e4.empty();
  ASSERT_TRUE(result2);

  // Test case 3: empty_impl(new Node(5)) should return false
  BinarySearchTree<int> e5; 
  bool result3 = e5.empty(); 
  ASSERT_TRUE(result3);
}

TEST(size_impl_test) {
  // Test case 1: size_impl(nullptr) should return 0
  BinarySearchTree<int> e1; 
  int result1 = e1.size();
  ASSERT_TRUE(result1 == 0);

  // Test case 2: size_impl(new Node()) should return 1
  BinarySearchTree<int> e2; 
  e2.insert(3);

  int result2 = e2.size(); 
  //
  ASSERT_TRUE(result2 == 1); 
//   Node *test_node2 = new Node();
//   int result2 = size_impl(test_node2);
//   ASSERT_TRUE(result2 == 1);

  // Test case 3: size_impl(root) should return 3
  // Test case 3: size_impl(root) should return 3
  BinarySearchTree<int> e3;
  e3.insert(5);
  e3.insert(3);
  e3.insert(7);

  int result3 = e3.size();
  ASSERT_TRUE(result3 == 3);
}




//if the insert function works correctly when inserting an element
//elements in the tree.
TEST(True_bst_public_test) {
  BinarySearchTree<int> tree;

  tree.insert(5);

  ASSERT_TRUE(tree.size() == 1);
  ASSERT_TRUE(tree.height() == 1);

  ASSERT_TRUE(tree.find(5) != tree.end());

  tree.insert(7);
  tree.insert(3);

  ASSERT_TRUE(tree.check_sorting_invariant());
  ASSERT_TRUE(*tree.max_element() == 7);
  ASSERT_TRUE(*tree.min_element() == 3);
  ASSERT_TRUE(*tree.min_greater_than(5) == 7);

  // Additional test cases
  ASSERT_FALSE(tree.find(4) != tree.end());
  ASSERT_FALSE(tree.find(6) != tree.end());
  
  tree.insert(4);
  
  ASSERT_TRUE(tree.find(4) != tree.end());
  
  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  
  ASSERT_TRUE(oss_preorder.str() == "5 3 4 7 ");
}



TEST(bst_iterator_test) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(7);
  tree.insert(3);
  tree.insert(4);

  ASSERT_TRUE(tree.size() == 4);
  ASSERT_TRUE(tree.check_sorting_invariant());

  auto it = tree.begin();
  
  ASSERT_TRUE(*it == 3);
  
  ++it;
  
  ASSERT_TRUE(*it == 4);
  
  ++it;
  
  ASSERT_TRUE(*it == 5);
  
  ++it;
  
  ASSERT_TRUE(*it == 7);
}




TEST(bst_min_greater_than_test_1) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(7);
  tree.insert(3);
  tree.insert(4);

  ASSERT_TRUE(tree.size() == 4);
  ASSERT_TRUE(tree.check_sorting_invariant());

  auto it = tree.min_greater_than(3);
  
  ASSERT_TRUE(it != tree.end());
  ASSERT_TRUE(*it == 4);
}

TEST(bst_min_greater_than_test_2) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(7);
  tree.insert(3);
  tree.insert(4);

  ASSERT_TRUE(tree.size() == 4);
  ASSERT_TRUE(tree.check_sorting_invariant());

  auto it = tree.min_greater_than(4);
  
  ASSERT_TRUE(it != tree.end());
  ASSERT_TRUE(*it == 5);
}

TEST(bst_min_greater_than_test_3) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(7);
  tree.insert(3);
  tree.insert(4);

  ASSERT_TRUE(tree.size() == 4);
  ASSERT_TRUE(tree.check_sorting_invariant());

  auto it = tree.min_greater_than(6);
  
  ASSERT_TRUE(it != tree.end());
  ASSERT_TRUE(*it == 7);
}








TEST(True_bst_traverse_preorder_test_1) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(7);
  tree.insert(3);
  tree.insert(4);

  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);

  ASSERT_TRUE(oss_preorder.str() == "5 3 4 7 ");
}

TEST(bst_traverse_preorder_test_2) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(6);

  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);

  ASSERT_TRUE(oss_preorder.str() == "5 3 7 6 ");
}

TEST(bst_traverse_preorder_test_3) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(4);
  tree.insert(2);

  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);

  ASSERT_TRUE(oss_preorder.str() == "5 3 2 4 ");
}




TEST(True_bst_height_test_1) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(7);
  tree.insert(3);
  tree.insert(4);

  ASSERT_TRUE(tree.height() == 3);
}

TEST(bst_height_test_2) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(6);

  ASSERT_TRUE(tree.height() == 3);
}

TEST(bst_height_test_3) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(4);
  tree.insert(2);

  ASSERT_TRUE(tree.height() == 3);
}




TEST(True_xD_bst_find_test_1) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(7);
  tree.insert(3);
  tree.insert(4);

  auto it = tree.find(3);
  
  ASSERT_TRUE(it != tree.end());
  ASSERT_TRUE(*it == 3);
}

TEST(bst_find_test_2) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(6);

  auto it = tree.find(6);
  
  ASSERT_TRUE(it != tree.end());
  ASSERT_TRUE(*it == 6);
}

TEST(bst_find_test_3) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(4);
  tree.insert(2);

  auto it = tree.find(2);
  
  ASSERT_TRUE(it != tree.end());
  ASSERT_TRUE(*it == 2);
}


TEST(True_bst_copy_ctor_test) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(7);
  tree.insert(3);
  tree.insert(4);

  BinarySearchTree<int> tree_copy(tree);

  ASSERT_TRUE(tree_copy.size() == 4);
  ASSERT_TRUE(tree_copy.check_sorting_invariant());

  auto it = tree_copy.find(3);
  
  ASSERT_TRUE(it != tree_copy.end());
  ASSERT_TRUE(*it == 3);
  
  it = tree_copy.find(4);
  
  ASSERT_TRUE(it != tree_copy.end());
  ASSERT_TRUE(*it == 4);
  
  it = tree_copy.find(5);
  
  ASSERT_TRUE(it != tree_copy.end());
  ASSERT_TRUE(*it == 5);
  
  it = tree_copy.find(7);
  
  ASSERT_TRUE(it != tree_copy.end());
  ASSERT_TRUE(*it == 7);
}







TEST(bst_height_test) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(2);
  tree.insert(4);
  tree.insert(6);
  tree.insert(8);

  ASSERT_TRUE(tree.height() == 3);
}

TEST(bst_find_test) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);

  auto it = tree.find(6);

  ASSERT_TRUE(it == tree.end());
}

TEST(bst_min_element_test) {
  BinarySearchTree<int> tree;

  tree.insert(-5);
  tree.insert(-3);
  tree.insert(-7);

  auto it = tree.min_element();

  ASSERT_TRUE(it != tree.end());
  ASSERT_TRUE(*it == -7);

  BinarySearchTree<int> empty_tree;
  
  it = empty_tree.min_element();

  ASSERT_TRUE(it == empty_tree.end());
}

TEST(bst_max_element_test) {
  BinarySearchTree<int> tree;

  tree.insert(-5);
  tree.insert(-3);
  tree.insert(-7);

  auto it = tree.max_element();

  ASSERT_TRUE(it != tree.end());
  ASSERT_TRUE(*it == -3);

  BinarySearchTree<int> empty_tree;
  
  it = empty_tree.max_element();

  ASSERT_TRUE(it == empty_tree.end());
}



TEST(blessed_bst_min_greater_than_test) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);

  auto it = tree.min_greater_than(8);

  ASSERT_TRUE(it == tree.end());
}


TEST(bst_traverse_inorder_impl_test_1) {
  BinarySearchTree<int> tree;

  std::ostringstream oss;
  tree.traverse_inorder(oss);

  ASSERT_TRUE(oss.str() == "");
}

TEST(bst_traverse_inorder_impl_test_2) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);

  std::ostringstream oss;
  tree.traverse_inorder(oss);

  ASSERT_TRUE(oss.str() == "3 5 7 ");
}

TEST(bst_traverse_inorder_impl_test_3) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(2);
  tree.insert(4);
  tree.insert(6);
  tree.insert(8);

  std::ostringstream oss;
  tree.traverse_inorder(oss);

  ASSERT_TRUE(oss.str() == "2 3 4 5 6 7 8 ");
}




TEST(hope_bst_traverse_preorder_impl_test_1) {
  BinarySearchTree<int> tree;

  std::ostringstream oss;
  tree.traverse_preorder(oss);

  ASSERT_TRUE(oss.str() == "");
}

TEST(bst_traverse_preorder_impl_test_2) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);

  std::ostringstream oss;
  tree.traverse_preorder(oss);

  ASSERT_TRUE(oss.str() == "5 3 7 ");
}

TEST(bst_traverse_preorder_impl_test_3) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(2);
  tree.insert(4);
  tree.insert(6);
  tree.insert(8);

  std::ostringstream oss;
  tree.traverse_preorder(oss);

  ASSERT_TRUE(oss.str() == "5 3 2 4 7 6 8 ");
}



TEST(bst_check_sorting_invariant_impl_test_1) {
  BinarySearchTree<int> tree;

  ASSERT_TRUE(tree.check_sorting_invariant());
}

TEST(bst_check_sorting_invariant_impl_test_2) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);

  ASSERT_TRUE(tree.check_sorting_invariant());
}

TEST(bst_check_sorting_invariant_impl_test_3) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);

  // manually change the value of a node to violate the sorting invariant
  *tree.begin() = 2;

  ASSERT_TRUE(tree.check_sorting_invariant());
}


//Tuesday
TEST(bst_check_sorting_invariant_impl_test_4) {
  BinarySearchTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);

  // manually change the value of a node to violate the sorting invariant
  *tree.begin() = 6;

  ASSERT_FALSE(tree.check_sorting_invariant());
}




//test terverse and print 
//tree empyty
//testing against tree
//

// void test_copy_nodes_impl() {
//   // Test case 1: copy_nodes_impl(nullptr) should return nullptr
//   assert(copy_nodes_impl(nullptr) == nullptr);
// }

// void test_destroy_nodes_impl() {
//   // Test case 1: destroy_nodes_impl(nullptr) should not cause any errors
//   destroy_nodes(nullptr);
// }

// int main() {
//   test_copy_nodes_impl();
//   test_destroy_nodes_impl();
//   return 0;
// }


// TEST(bst_insert_duplicate_test) {
//   BinarySearchTree<int> tree;

//   tree.insert(5);
//   tree.insert(3);
//   tree.insert(7);

//   ASSERT_TRUE(tree.size() == 3);
//   ASSERT_TRUE(tree.check_sorting_invariant());

//   tree.insert(3);

//   ASSERT_TRUE(tree.size() == 3);
//   ASSERT_TRUE(tree.check_sorting_invariant());
// }
//error
TEST(bst_simple) {
    BinarySearchTree<int> tree; 
    tree.insert(2);
 ASSERT_TRUE(tree.size() == 1);
  ASSERT_TRUE(tree.height() == 1);

  ASSERT_FALSE(tree.find(5) != tree.end());

  tree.insert(7);
  tree.insert(3);
}



//nonrev
TEST(unique_test_1) {
  std::vector<int> v = {1, 2, 3, 4};
  ASSERT_TRUE(std::unique(v.begin(), v.end()) == v.end());
}

TEST(unique_test_2) {
  std::vector<int> v = {1, 2, 2, 3};
  ASSERT_TRUE(std::unique(v.begin(), v.end()) != v.end());
}

TEST(unique_test_3) {
  std::vector<int> v = {1, 1, 1, 1};
  ASSERT_TRUE(std::unique(v.begin(), v.end()) != v.end());
}




//Tuesday18
TEST(True_bst_min_element_empty_tree_test) {
  BinarySearchTree<int> tree;
  
  ASSERT_TRUE(tree.min_element() == tree.end());
}

TEST(True_bst_max_element_empty_tree_test) {
  BinarySearchTree<int> tree;
  
  ASSERT_TRUE(tree.max_element() == tree.end());
}




TEST_MAIN()
