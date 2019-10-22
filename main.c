#include<stdint.h>
#include<stdlib.h>
#include<assert.h>
#include<stddef.h>
#include<stdbool.h>
#include<stdio.h>

#include"bst.h"
//#include"queue.h"


BST bst_new()
{
	BST tree={NULL,0};
	return tree;
}

static Node* create_new_node(int32_t ele)
{
	Node *node=(Node*)malloc(sizeof(Node));
	node->data=ele;
	node->left=NULL;
	node->right=NULL;
	return node;
}

uint32_t bst_count(BST *tree)
{
	assert(tree!=NULL);
	return tree->count;
}

BST* add_node(BST *tree, int32_t ele)
{
	assert(tree!=NULL);

	Node *temp=create_new_node(ele);

	if(tree->root==NULL)
	{
		tree->root=temp;
		tree->count++;
		return tree;
	}

	Node *cur=tree->root;

	while(true)
	{
		if(ele<cur->data)
		{
			if(cur->left==NULL)
			{
				cur->left=temp;
				tree->count++;
				break;

			}
			else cur=cur->left;
		}

		else if(ele>cur->data)
		{
			if(cur->right==NULL)
			{
				cur->right=temp;
				tree->count++;
				break;
			}
			else cur=cur->right;

		}

		else break;
	}

	return tree;
}

BST* delete_node(BST* tree, int32_t key)
{
    assert(tree!=NULL);
    if(tree->root==NULL) return tree;
    Node *temp=tree->root;
    if((temp->data==key) && (temp->left==NULL) &&(temp->right==NULL))
    {
        tree->root=NULL;
        free(temp);
        tree->count--;
        return tree;
    }
    Node *prev=temp;

    while(temp!=NULL)
    {
        if(temp->data==key) break;
        else
        {
            prev=temp;
            if(key>temp->data) temp=temp->right;
            else temp=temp->left;
        }
    }

    if(temp==NULL) return tree;

L1: if((temp->left==NULL) && (temp->right==NULL))
    {
        if(key>prev->data) prev->right=NULL;

        else prev->left=NULL;
    }

    else if((temp->left==NULL)&&(temp->right!=NULL))
    {
        if(key>prev->data) prev->right=temp->right;
        else prev->left=temp->right;
    }

    else if((temp->left!=NULL)&&(temp->right==NULL))
    {
        if(key>prev->data) prev->right=temp->left;
        else prev->left=temp->left;
    }

    else
    {
        Node *cur=temp->right;
        Node *just=cur;
        while(cur->left!=NULL)
        {
            just=cur;
            cur=cur->left;
        }

        temp->data=cur->data;
        temp=cur;
        prev=just;
        goto L1;
    }

    free(temp);
    tree->count--;
    return tree;
}

void bst_inorder(BST *tree)
{
	assert(tree!=NULL);
	_inorder_(tree->root);
}

void _inorder_(Node *node)
{
	if(node)
	{
		_inorder_(node->left);
		printf("%d\t", node->data );
		_inorder_(node->right);
	}
}



