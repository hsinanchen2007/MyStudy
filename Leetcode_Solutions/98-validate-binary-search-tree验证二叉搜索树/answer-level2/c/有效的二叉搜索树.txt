### 解题思路

 从根节点开始递归遍历左右子树，左子树上的所有节点都要小于根节点，右子树上所有节点都要大于根节点，所以递归方法需要有最大最小两个边界值
 1. 如果当前节点为空，则返回true
 2. 如果当前节点小于最小边界，或者大于最大边界，则为false
 3. 然后在分别递归左子树和右子树，
    * 递归左子树时，最小值仍然是最小值，左子树的所有节点值都不能超过当前值
    * 递归右子树时，最大值仍然是最大值，右子树的所有节点值都不能小于当前值

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

bool func(struct TreeNode *root, long low, long high){
    if (root == NULL) {
        return true;
    }
    if (root->val <= low || root->val >= high) {
        return false;
    }
    return func(root->left, low, root->val) && func(root->right, root->val, high);
}

bool isValidBST(struct TreeNode* root){
    return func(root, LONG_MIN, LONG_MAX);
}
```