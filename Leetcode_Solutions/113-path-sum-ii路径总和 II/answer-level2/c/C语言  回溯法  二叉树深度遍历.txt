### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 5000
struct My_Node {
    int data;
    struct My_Node * next;
};

void init_stack(struct My_Node **sentinel){
    struct My_Node *ptr=malloc(sizeof(struct My_Node));
    ptr->data=0;
    ptr->next=NULL;
	*sentinel=ptr;
}

void push(struct My_Node *sentinel, int num){
    struct My_Node *ptr=NULL;
    ptr=malloc(sizeof(struct My_Node));
    ptr->data=num;
    ptr->next=NULL;
    if(!sentinel->next){
        sentinel->next=ptr;
    }else{
        ptr->next=sentinel->next;
        sentinel->next=ptr;
    }
	sentinel->data++;
}

void pop(struct My_Node *sentinel){
    struct My_Node *ptr=NULL;
    ptr=sentinel->next;
    sentinel->next=ptr->next;
	sentinel->data--;
    free(ptr);
}

void result_add(int ** ret_array, int *returnSize, struct My_Node *sentinel, int *returnColumnSizes){
	int index=*returnSize;
	int colmunSize=sentinel->data;
	int *ptr=ret_array[index]=malloc(sizeof(int)*colmunSize);
	returnColumnSizes[index]=colmunSize;
	int ii=colmunSize-1;
	struct My_Node* tmp_ptr=sentinel->next;
	while(tmp_ptr!=NULL){
		ptr[ii]=tmp_ptr->data;
		ii--;
		tmp_ptr=tmp_ptr->next;
	}
	*returnSize=index+1;
}

void destroy(struct My_Node *sentinel){
		while(sentinel->next !=NULL){
			pop(sentinel);		
		}
	
}
void traverse(struct TreeNode* root, int sum, struct My_Node *sentinel, int ** ret_array, int *returnColumnSizes, int *returnSize){
	if(root == NULL){
		return;
	}
	
	push(sentinel, root->val);
	if(root->left == NULL && root->right == NULL){
		if(root->val == sum){
			result_add(ret_array, returnSize, sentinel, returnColumnSizes);
		}
	}
	int target =sum-root->val;
	traverse(root->left, target, sentinel, ret_array, returnColumnSizes, returnSize);
	traverse(root->right, target, sentinel, ret_array, returnColumnSizes, returnSize);
	pop(sentinel);
	
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
	int **ret_array=malloc(sizeof(int*)*MAX_SIZE);
	*returnColumnSizes=malloc(sizeof(int)*MAX_SIZE);
	*returnSize=0;
	struct My_Node * sentinel=NULL;
	init_stack(&sentinel);
	traverse(root, sum, sentinel, ret_array, *returnColumnSizes, returnSize);
	destroy(sentinel);
	return ret_array;
}
```