### 解题思路
此处撰写解题思路

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
public:
    int sumOfLeftLeaves(TreeNode* root) {

        int lsum;
        int rsum;
        if(!root)return 0;
        if(!root->left&&!root->right)return 0;
        if(root->left&&!root->left->left&&!root->left->right)
            lsum= root->left->val;
        else
            lsum=sumOfLeftLeaves(root->left);
        rsum=sumOfLeftLeaves(root->right);
   
        return lsum+rsum;
    }
};
```