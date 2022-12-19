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
        TreeNode *l = root->left ? lowestCommonAncestor(root->left, p, q) : nullptr;
        TreeNode *r = root->right ? lowestCommonAncestor(root->right, p, q) : nullptr;
        return (root == p or root == q or (l and r)) ? root : l ? l : r;
    }
};
```
- 递归全部节点，p 的祖先节点全部返回 p，q 的祖先节点全部返回 q，如果它同时是俩个节点的最近祖先，那么返回自身，否则返回 nullptr