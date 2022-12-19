层序遍历，按照队列先进先出的特点，总是让右子树先进，如果存在右子树，则入队，之后左子树入队。
每一层遍历中，只将队头节点，也就是每一层中最右的节点的值作为最后的结果，加入ret中。
```
int* rightSideView(struct TreeNode* root, int* returnSize){
    *returnSize=0;
    if(root==NULL){
        return NULL;
    }
    int *ret=malloc(sizeof(int)*1000);
    int rear=0,front=0;
    struct TreeNode **queue=malloc(sizeof(struct TreeNode*)*1000);
    queue[rear++]=root;
    while(rear!=front){
        struct TreeNode *node=queue[front]; 
        ret[(*returnSize)++]=node->val;
        int size=rear-front;
        while(size){
            struct TreeNode *node=queue[front++]; 
            if(node->right){
                queue[rear++]=node->right;
                }
            if(node->left){
                queue[rear++]=node->left;  
           }
           size--;
        }
    }
    return ret;
}
```
