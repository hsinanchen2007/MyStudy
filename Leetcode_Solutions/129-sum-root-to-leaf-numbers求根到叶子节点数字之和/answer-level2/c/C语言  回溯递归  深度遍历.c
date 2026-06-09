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
void traverse(struct TreeNode* root,  struct My_Node *sentinel, int ** ret_array, int *returnColumnSizes, int *returnSize){
	if(root == NULL){
		return;
	}
	
	push(sentinel, root->val);
	if(root->left == NULL && root->right == NULL){
		result_add(ret_array, returnSize, sentinel, returnColumnSizes);
	}
	
	traverse(root->left, sentinel, ret_array, returnColumnSizes, returnSize);
	traverse(root->right, sentinel, ret_array, returnColumnSizes, returnSize);
	pop(sentinel);
	
}

int sumNumbers(struct TreeNode* root){
	int **ret_array=malloc(sizeof(int*)*MAX_SIZE);
	int *returnColumnSizes=malloc(sizeof(int)*MAX_SIZE);
	int returnSize=0;
	struct My_Node * sentinel=NULL;
	init_stack(&sentinel);
	traverse(root, sentinel, ret_array, returnColumnSizes, &returnSize);
	destroy(sentinel);
	int ii=0;
	int sum=0;
	for(;ii<returnSize;ii++){
		int jj=0;
		int tmp_sum=0;
		for(;jj<returnColumnSizes[ii];jj++){
			tmp_sum=tmp_sum*10+ret_array[ii][jj];
		}
		free(ret_array[ii]);
		sum+=tmp_sum;	
	}
	free(ret_array);
	free(returnColumnSizes);
	return sum;
	
}