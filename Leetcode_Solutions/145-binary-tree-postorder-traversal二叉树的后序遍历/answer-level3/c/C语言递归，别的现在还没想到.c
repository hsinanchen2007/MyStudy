### 解题思路
C语言递归，别的现在还没想到。
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
 #define  MAX_SIZE 100
void posttravl(struct TreeNode* root, int* retarray, int* returnSize) {
    if(root == NULL) {
        return;
    }
    posttravl(root->left, retarray, returnSize);
    posttravl(root->right, retarray, returnSize);
    retarray[*returnSize] = root->val;
    (*returnSize)++;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    if(root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 0;
    int* retarray = (int*)malloc(sizeof(int) * MAX_SIZE);
    memset(retarray, 0, sizeof(int) *MAX_SIZE);
    posttravl(root, retarray, returnSize);
    return retarray;
}
```