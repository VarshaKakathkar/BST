#ifndef _INCLUDED_BST_
#define _INCLUDED_BST_
#include<stdint.h>

typedef struct  _tree_node TreeNode;
typedef struct  _bst_ BST;

struct _tree_node
{
	int32_t data;
	TreeNode* left;
	TreeNode* right;
};

struct _bst_
{
	TreeNode *root;
	uint32_t mass;
};

BST bst_new();
uint32_t bst_count(BST *tree);
BST* bst_add_node(BST *tree, int32_t element);
BST* bst_delete_node(BST *tree, int32_t key);
uint32_t bst_lookup(BST *tree);
BST* bst_inorder(BST *tree);
BST* bst_postorder(BST *tree);
BST* bst_preorder(BST *tree);
uint32_t bst_hieght(BST *tree);
BST* bst_level_order(BST *tree);

static void _inorder_(TreeNode *node);
static void _postorder_(TreeNode *node);
static void _preorder_(TreeNode *node);

#endif
