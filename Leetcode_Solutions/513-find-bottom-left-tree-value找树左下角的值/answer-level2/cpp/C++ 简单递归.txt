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
    void dfs(TreeNode* root, int x, int y, int& xmn, int& ymx, int& res) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            if (y > ymx) {
                res = root->val;
                xmn = x;
                ymx = y;
            } else if (y == ymx && x < xmn) {
                res = root->val;
                xmn = x;
            }
            return;
        }
        dfs(root->left, x - 1, y + 1, xmn, ymx, res);
        dfs(root->right, x + 1, y + 1, xmn, ymx, res);
    }
    int findBottomLeftValue(TreeNode* root) {
        if (root == NULL) return 0;
        int res = 0;
        int xmn = INT_MAX;
        int ymx = 0;
        dfs(root, 0, 0, xmn, ymx, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/803211a813a8da6926b553eb5dee4c7f898bf635aa41f2cb616fb3ab9ac7bf77-image.png)
