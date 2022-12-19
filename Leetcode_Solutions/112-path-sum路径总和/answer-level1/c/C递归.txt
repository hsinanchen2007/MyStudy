### 解题思路
递归判断左右子树，递归时sum减去当前根节点的值，到叶结点处返回，叶结点中有一个返回true即可

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


bool hasPathSum(struct TreeNode* root, int sum){
    if(!root)//空树
        return false;
    if(!root->left && !root->right)//若是叶子结点，判断加上其值能否等于目标和
        return sum == root->val;
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}
```