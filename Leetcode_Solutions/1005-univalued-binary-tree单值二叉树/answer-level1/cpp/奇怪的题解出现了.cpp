### 解题思路
反正别人写成这样我是看不懂（

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
    bool isUnivalTree(TreeNode* root,int p=-1) {
        return p==-1?(!root->left||isUnivalTree(root->left,root->val))&&(!root->right||isUnivalTree(root->right,root->val)) : root->val==p&&(!root->left||isUnivalTree(root->left,p))&&(!root->right||isUnivalTree(root->right,p));
    }
};
```