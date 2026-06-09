### 解题思路
* 递归
* 情况1 root为空返回false
* 情况2 root为叶子节点判断是否sum等于root->val；
* 情况3 root不是叶子节点，递归判断root->left或者root->right是否满足hasPathSum

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
   if (!root) return false; //如果只有根节点为空的话返回false
   if ((sum==root->val)&&!root->left&&!root->right) //叶子节点等于sum
   {
       return true;
   }
   int diff = sum - root->val;
   return (hasPathSum(root->left,diff) || hasPathSum(root->right,diff));
    
}
```