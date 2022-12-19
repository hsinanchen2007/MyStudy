这种问题用C语言真的很蛋疼，主要是C语言不支持变长数组，所以比较痛苦。
```
int maxDepth(struct TreeNode* root){
    int left =0;
    int right =0;
    if(root == NULL){
        return 0;
    }    

    left = maxDepth(root->left);
    right = maxDepth(root->right);
    return 1 + (left > right ? left : right);
}

int NodeNum(struct TreeNode* root){
    int left =0;
    int right =0;
    if(root == NULL){
        return 0;
    }    

    left = NodeNum(root->left);
    right = NodeNum(root->right);
    return 1 + left +right;
}

// 需要用到队列来进行BFS
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = maxDepth(root);
    if(root==NULL){
        (*returnColumnSizes)=0;
        return NULL;
    }
    
    int** result = (int**)malloc( (*returnSize)*sizeof(int*) );
    *returnColumnSizes = (int*)malloc( (*returnSize)*sizeof(int) );
    
    //创建一个queue来存放BFS的遍历临时值
    int nodeNum = NodeNum(root);
    // printf("nodeNum:%d\n", nodeNum);
    int head = 0;
    int tail = 0;
    struct TreeNode** queue = (struct TreeNode**)calloc( nodeNum, sizeof(struct TreeNode*));
    int m=0;
    int n=0;
    int k=0;
    queue[tail++] = root;
    
    while(root !=NULL && head != tail ){
        result[m] = (int*)calloc( (*returnSize)*(*returnSize), sizeof(int) );
        while(head < tail ){
            root = queue[head];
            result[m][n] = root->val;
            n++;
            head++;
        }
        
        (*returnColumnSizes)[k++] = n;
        int tmp = head;
        head = head-n;
        while(head<tmp){
            root = queue[head++];
            if(root->left)
                queue[tail++] = root->left;
            if(root->right)
                queue[tail++] = root->right;
        }
        n=0;
        m++;
        
    }
    
    free(queue);
    return result;
}

```
