
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "bst.h"


int main()
{
BST bst = bst_new();
BST *tree = &bst;
//1. Design a BST class with methods to add element, search element, number of elements and delete requested element
tree = add_node(tree,50);
assert((tree->root->left==NULL) && (tree->root->right==NULL));
tree=delete_node(tree,100);
tree = add_node(tree,20);
tree=delete_node(tree,20);
tree = add_node(tree,30);
tree = add_node(tree,60);
tree = add_node(tree,70);
tree = add_node(tree,35);
tree = add_node(tree,40);
tree = add_node(tree,20);
tree = add_node(tree,25);
tree = add_node(tree,15);
tree=delete_node(tree,100);
tree=delete_node(tree,25);
tree=delete_node(tree,35);
tree=delete_node(tree,60);
tree=delete_node(tree,50);
assert(tree->root->data==70);

assert(tree->count == 5);

//2. Add methods to in-order, pre-order, post-order and level-order traversals
printf("In-order: ");
bst_inorder(tree);

return 0 ;

}
