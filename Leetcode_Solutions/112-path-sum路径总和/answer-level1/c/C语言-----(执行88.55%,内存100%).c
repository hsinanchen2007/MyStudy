### 解题思路
此处撰写解题思路

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
if(!root)     //将root为NULL的条件排除
return false;
if(root->left==NULL&&root->right==NULL){
    return root->val==sum?true:false;
}
//sum从根节点开始减去当前节点的值，该树中若存在根节点到叶子节点的路径，则减到叶子节点，sum==叶子节点的值
return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
}
```