```
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
    const int MIN_V = -1e6;
    int dfs(TreeNode** root, int limit) {
        if (*root == NULL) return MIN_V;
        if ((*root)->left == NULL && (*root)->right == NULL) {
            int v = (*root)->val;
            if ((*root)->val < limit) *root = NULL;
            return v;
        }
        int l = dfs(&(*root)->left, limit - (*root)->val);
        int r = dfs(&(*root)->right, limit - (*root)->val);
        int v = (*root)->val + max(l, r);
        if (v < limit) *root = NULL;
        return v;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (root == NULL) return root;
        TreeNode** pnode = &root;
        dfs(pnode, limit);
        return root;
    }
};
```
![image.png](https://pic.leetcode-cn.com/bbfd3b36d2a13da16477fc9db635987e55ae436fa8d53cf40688a1c8abf24ab8-image.png)


