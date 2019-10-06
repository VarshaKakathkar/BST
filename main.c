
#include<stdlib.h>
#include<assert.h>
#include<stddef.h>
#include<stdio.h>

#include"bst.h"
#include"queue.h"


BST bst_new()
{
BST btree={NULL,0};
return btree;
}

static TreeNode* _bst_newnode(int32_t ele)
{
	TreeNode *node=(TreeNode*) malloc(sizeof(TreeNode));
	node->data=ele;
	node->left=NULL;
	node->right=NULL;
	return node;
}

uint32_t bst_count(BST *tree)
{
	assert(tree!=NULL);
	return tree->mass;
}
BST* bst_add_node(BST *tree, int32_t element)
{
	assert(tree!=NULL);
	Treenode *cur, *parent;
	cur=parent=tree->root;
	while(cur!=NULL && cur->data!=element)
	{
		parent=cur;
		if(element<cur->data)
		{
			cur=cur->left;
		}
		else if(element>cur->data)
		{
			cur=cur->right;
		}
	}
	if(cur==NULL)
	{
		Treenode *tnode=_bst_newnode(element);
		if(parent==NULL)
		{
			tree->root=tnode;
		}
		else if(element<parent->data)
		{
			parent->left=tnode;
		}
		else if(element>parent->data)
		{
			parent=>right=tnode;
		}
		++tree->mass;
	}
	return tree;
}

BST* bst_delete_node(BST *tree, int32_t key)
{





}
uint32_t bst_lookup(BST *tree)
{
	assert(tree!=NULL);
	Treenode *cur=tree->root;
	while(cur!=NULL && cur->data!=key)
	{
		if(key<cur->data)
		{
			cur=cur->left;
		}
		else if(element>cur->data)
		{
			cur=cur->right;
		}
	}
	return (cur!=NULL);
}
BST* bst_inorder(BST *tree)
{
	assert(tree!=NULL);
	_inorder_(tree->root);
}
static void _inorder_(Treenode *node)
{
	if(node)
	{
		_inorder_(node->left);
		printf("%d\t", node->data );
		_inorder_(node->left);
	}
}
BST* bst_postorder(BST *tree)
{
	assert(tree!=NULL);
	_postorder_(tree->root);
}
static void _postorder_(Treenode *node)
{
	if(node)
	{
		_postorder_(node->left);
		_postorder_(node->left);
		printf("%d\t", node->data );
	}
}
BST* bst_preorder(BST *tree)
{
	assert(tree!=NULL);
	_preorder_(tree->root);
}
static void _preorder_(Treenode *node)
{
	if(node)
	{
		printf("%d\t", node->data );
		_preorder_(node->left);
		_preorder_(node->left);
	}
}
uint32_t bst_hieght(BST *tree)
{



}
BST* bst_level_order(BST *tree)
{
	assert(tree->root!=NULL);
	Treenode *node;
	Queue bst_q=queue_new(tree->mass);
	queue *q=&bst_q;
	queue_res res;

	q=queue_add(q,tree->root,&res);
	while(!queue_empty(q))
	{
	queue_delete(q,&res);
	node=(Treenode*) res.data;
	if(node->left)
	{
	  queue_add(q,node->left,&res);
	}
	if(node->right)
	{
		queue_add(q,node->right,&res);

	}
	printf("%d\t", node->data);
	}
}
