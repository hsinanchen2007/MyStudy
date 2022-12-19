按照先序遍历的方法递归查找即可
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
    void dfs(TreeNode* root, vector<int>& voyage, int l, int r, bool& valid, vector<int>& res) {
        if (!valid || root == NULL || l > r) return;
        if (root->val != voyage[l]) {
            valid = false;
            return;
        }
        if (root->left == NULL || root->right == NULL) {
            auto child = root->right ? root->right : root->left;
            dfs(child, voyage, l + 1, r, valid, res);
            return;
        }
        int vl = root->left->val;
        int vr = root->right->val;
        int il = -1;
        int ir = -1;
        for (int i = l; i <= r; ++i) {
            if (voyage[i] == vl) il = i;
            if (voyage[i] == vr) ir = i;
        }
        if (il == -1 || ir == -1) {
            valid = false;
            return;
        }
        if (il > ir) {
            res.push_back(root->val);
            dfs(root->left, voyage, il, r, valid, res);
            dfs(root->right, voyage, l + 1, il - 1, valid, res);
        } else {
            dfs(root->left, voyage, l + 1, ir - 1, valid, res);
            dfs(root->right, voyage, ir, r, valid, res);
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        bool valid = true;
        dfs(root, voyage, 0, voyage.size() - 1, valid, res);
        if (valid) return res;
        return {-1};
    }
};
```

![image.png](https://pic.leetcode-cn.com/37b706baccf555957f6306fcf46e3d2244863909db943ab52049d42db2b31390-image.png)
