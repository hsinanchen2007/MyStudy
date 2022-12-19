### 解题思路
从根节点开始，通过递归的方式以此判断其子节点是否对称
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
	bool SynTree(TreeNode* left, TreeNode* right) {
		if (left == nullptr&&right == nullptr)return true;
		if (left == nullptr || right == nullptr)return false;
		if (left->val != right->val)return false;
		return SynTree(left->left, right->right) && SynTree(right->left, left->right);
	}
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)return true;
		return SynTree(root->left, root->right);
	}
};
```