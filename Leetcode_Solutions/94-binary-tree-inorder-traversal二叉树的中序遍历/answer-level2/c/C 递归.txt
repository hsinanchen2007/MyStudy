
每次不使用malloc、calloc，必然有别的变量报错，不知道为什么

```
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
void inorderTraversalIter(struct TreeNode*, int*, int*);
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    //int temp[200] = {0};
    int* temp = (int*)calloc(200, sizeof(int));
    *returnSize = 0;
    inorderTraversalIter(root, temp, returnSize);
    return temp;
}

void inorderTraversalIter(struct TreeNode* root, int* res, int* returnSize){
    if (root){
        inorderTraversalIter(root->left, res, returnSize);
        res[*returnSize] = root->val;
        (*returnSize)++;
        inorderTraversalIter(root->right, res, returnSize);
    }
    return;
}
```
