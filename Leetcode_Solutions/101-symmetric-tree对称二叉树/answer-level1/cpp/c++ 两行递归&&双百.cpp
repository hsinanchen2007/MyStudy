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
    bool issym(TreeNode*left,TreeNode*right)
    {
        return (left==NULL||right==NULL)?left==right:(left->val==right->val)&&issym(left->left,right->right)&&issym(left->right,right->left) ;
    }
    bool isSymmetric(TreeNode* root) {   
        return root==NULL?1:issym(root->left,root->right);
    }
};
```