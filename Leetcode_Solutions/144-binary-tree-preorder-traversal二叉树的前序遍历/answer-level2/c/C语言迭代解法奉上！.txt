
# 利用数组模拟栈的操作，完成迭代算法的实现。

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
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * 100),top = -1;
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
    *returnSize = 0;
    if(!root) return NULL;
    stack[++top] = root;
    while(top != -1)
    {
        root = stack[top--];
         res[(*returnSize)++] = root->val;
        if(root->right)
        {
            stack[++top] = root->right;
        }
        if(root->left)
        {
            stack[++top] = root->left;
        }
    }
    return res;
}
```
