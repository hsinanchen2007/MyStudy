### 解题思路
右 中 左

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
    int val;
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL)return root;
        bstToGst(root->right);
        val += root->val;
        root->val = val;
        bstToGst(root->left);
        return root;
    }
};
```