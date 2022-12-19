### 解题思路
递归

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


int pathSum(struct TreeNode* root, int sum){
    if(!root) return 0;
    return pathSum2(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
     
}
int pathSum2(struct TreeNode* root, int sum){
    if(!root) return 0;
    if(root->val == sum) 
        return 1 + pathSum2(root->left,sum - root->val) + pathSum2(root->right,sum - root->val);
    else
        return pathSum2(root->left,sum - root->val) + pathSum2(root->right,sum - root->val);
}

```