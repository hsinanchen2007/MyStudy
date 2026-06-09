### 解题思路
好像无论先序 中序 后序都可以解
可以用swap

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
    TreeNode* invertTree(TreeNode* root) {
      if(!root) return NULL;

      swap(root->left, root->right);
      root->left = invertTree(root->left);
      root->right = invertTree(root->right);

      return root;
    }
};
```