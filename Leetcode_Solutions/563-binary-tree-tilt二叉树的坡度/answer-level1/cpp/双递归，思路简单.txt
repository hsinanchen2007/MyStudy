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
 int sum(TreeNode *root)
 {
     if(!root)return 0;
     else return root->val+sum(root->left)+sum(root->right);
 }
class Solution {
public:
    int findTilt(TreeNode* root) {
        if(!root)return 0;
        if(!root->left&&!root->right)return 0;

        return abs(sum(root->left)-sum(root->right))+findTilt(root->left)+findTilt(root->right);
    }
};
```