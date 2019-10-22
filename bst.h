#ifndef _INCLUDED_BST_
#define _INCLUDED_BST_
#include<stdint.h>

typedef struct  _tree_node Node;
typedef struct  _bst_ BST;

struct _tree_node
{
	int32_t data;
	Node *left;
	Node *right;
};

struct _bst_
{
	Node *root;
	uint32_t count;
};

BST bst_new();
uint32_t bst_count(BST *tree);
BST* add_node(BST *tree,int32_t element);
BST* delete_node(BST* tree,int32_t key);
void bst_inorder(BST *tree);
void _inorder_(Node *node);

#endif
