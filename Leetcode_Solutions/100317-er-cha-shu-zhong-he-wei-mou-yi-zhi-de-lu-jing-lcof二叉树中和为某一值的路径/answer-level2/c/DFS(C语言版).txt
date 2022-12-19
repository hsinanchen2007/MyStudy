### 解题思路
常规深度优先搜索

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
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    if (!root){
        *returnSize = 0;
        return NULL;
    }
    int **ans,top=-1,*p;
    ans = (int**)malloc(sizeof(int*)*1000);//很烦这样盲目开辟空间
    p = (int*)malloc(sizeof(int*)*1000);
    void DFS(struct TreeNode *rt,int pre_sum,int *num,int numSize){
        if (!rt->left && !rt->right){
            if (pre_sum+rt->val==sum){
                int *new_num;
                new_num = (int*)malloc(sizeof(int)*(numSize+1));
                for (int i=0;i<numSize;i++)
                    new_num[i] = num[i];
                new_num[numSize] = rt->val;
                ans[++top] = new_num;
                p[top] = numSize+1;
            }
        }
        else{
            int *new_num;
            new_num = (int*)malloc(sizeof(int)*(numSize+1));
            for (int i=0;i<numSize;i++)
                new_num[i] = num[i];
            new_num[numSize] = rt->val;
            if (rt->left)
                DFS(rt->left,pre_sum+rt->val,new_num,numSize+1);
            if (rt->right)
                DFS(rt->right,pre_sum+rt->val,new_num,numSize+1);
        }
    }
    DFS(root,0,NULL,0);
    *returnSize = top+1;
    *returnColumnSizes = p;
    return ans;
}
```