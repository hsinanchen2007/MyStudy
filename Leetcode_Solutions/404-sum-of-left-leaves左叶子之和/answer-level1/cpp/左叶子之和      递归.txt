### 解题思路
左叶子条件：root->left!=NULL&&root->left->right==NULL&&root->left->left==NULL

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int sum=0;
    void helper(TreeNode* root){
        if(!root) return;
        if(root->left!=NULL&&root->left->right==NULL&&root->left->left==NULL)
           sum+=root->left->val;
        helper(root->left);
        helper(root->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root);
        return sum;
    }
};
```