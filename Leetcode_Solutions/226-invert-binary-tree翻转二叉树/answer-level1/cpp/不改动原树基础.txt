### 解题思路
是在不改动原树的基础上进行的操作
关键点每一次递归进函数的时候需要new TreeNode*
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
       if (root == nullptr) return nullptr;
	   TreeNode* node = new TreeNode(root->val);
	   node->left = invertTree(root->right);
	   node->right = invertTree(root->left);
	   return node;
    }
};
```