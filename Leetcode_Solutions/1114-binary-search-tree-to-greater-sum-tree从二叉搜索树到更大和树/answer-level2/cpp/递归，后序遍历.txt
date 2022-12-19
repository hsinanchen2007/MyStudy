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
private:
    int val = 0;

public:
    TreeNode* bstToGst(TreeNode* root) {
        if (root == NULL)  return root;
        bstToGst(root->right);
        val = val + root->val;
        root->val = val;
        bstToGst(root->left);
        return root;
    }
};
```