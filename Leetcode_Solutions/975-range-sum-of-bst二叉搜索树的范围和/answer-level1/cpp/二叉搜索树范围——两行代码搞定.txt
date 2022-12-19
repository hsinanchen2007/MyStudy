### 解题思路
先序遍历之递归。

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL) return 0;
        return (root->val>=L&&root->val<=R?root->val:0)+rangeSumBST(root->left, L, R)+rangeSumBST(root->right, L, R);
    }
};
```