```
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    * returnSize=0;
    if(root==NULL){
        return NULL;
    }
    *returnColumnSizes=malloc(sizeof(int)*100);
    int **ret=malloc(sizeof(int)*100);
    struct TreeNode**queue=malloc(sizeof(struct TreeNode*)*10000);
    int rear=0,front=0;
    queue[rear++]= root;
    int level=0;
    while(rear!=front){
        int size=rear-front;
        (*returnColumnSizes)[level]=size;
        ret[level]=malloc(sizeof(int)*size);
        int i=0;
        while(size){
            struct TreeNode*node=queue[front++];
            if(level%2==0)
                ret[level][i++]=node->val;
            else 
                ret[level][size-1]=node->val;
            if(node->left)
                queue[rear++]=node->left;
            if(node->right)
                queue[rear++]=node->right;
            size--;
        }
        level++;
    }
    *returnSize=level;
    return ret;
}
```
