### 解题思路
参考层次遍历

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
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef  struct{
    int r;
    int w;
    //int size;
    struct TreeNode * q[1000];
}Que;

 int getdepth(struct TreeNode * root){
     int left,right;
     if(root == 0)
        return 0;
      if(root->left == NULL && root->right ==NULL)
        return 1;
     left = getdepth(root->left);
     right = getdepth(root->right);

     return (left > right ? left : right) + 1; 
 }

int enqueue(Que * q, struct TreeNode * node){
    if(q->w == 1000)
        return -1;
    
    q->q[q->w++] = node;
    return 0;
}
struct TreeNode* dequeue(Que *q){
    if(q->r >= q->w)
        return NULL;
    return q->q[q->r++];
}

int* rightSideView(struct TreeNode* root, int* returnSize){
        Que *nQue = malloc(sizeof(Que));
        struct TreeNode * node;
        int res[100][100],i=0,j=0,len;
        int *arr = malloc(sizeof(int) * 100);

        memset(nQue,0,sizeof(Que));
        if(root == NULL){
            *returnSize = 0;
            return NULL;
        }
        enqueue(nQue,root);
        //printf("'aaa2\n");
        while(nQue->w - nQue->r){
            len = nQue->w - nQue->r;
            //printf("'bbb\n");
            while(len--){
                node = dequeue(nQue);
                if(node->left)
                    enqueue(nQue,node->left);
                if(node->right)
                    enqueue(nQue,node->right);
                res[i][j++] = node->val;
            }
            arr[i++] = res[i][j-1];
            j = 0;
        }
        *returnSize = i;
        return arr;
}
```