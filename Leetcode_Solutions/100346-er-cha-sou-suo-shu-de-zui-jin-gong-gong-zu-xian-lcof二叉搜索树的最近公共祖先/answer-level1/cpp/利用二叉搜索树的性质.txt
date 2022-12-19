### 解题思路
对于一棵二叉搜索树，任意一个节点的值大于其所有左子树的值而小于其所有右子树的值。

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root)return nullptr;
		if (p->val<=root->val&&q->val>=root->val)return root;
		if (p->val >= root->val&&q->val <= root->val)return root;
		if (p->val > root->val&&q->val > root->val)return lowestCommonAncestor(root->right, p, q);
		if (p->val < root->val&&q->val < root->val)return lowestCommonAncestor(root->left, p, q);
        return nullptr;
    }
};
```