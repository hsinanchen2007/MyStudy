# 解法一：
```C++ []
    int helper(TreeNode* root, int& max_path) {
        if (root == NULL) return 0;
        int left = max(helper(root->left, max_path), 0);
        int right = max(helper(root->right, max_path), 0);
        max_path = max(max_path, left + right + root->val);
        return max(left + root->val, right + root->val);
    }
    int maxPathSum(TreeNode* root) {
        int max_path = INT_MIN;
        helper(root, max_path);
        return max_path;
    }
};
```
![image.png](https://pic.leetcode-cn.com/dd0a91683d4b5255611beed2fa0250ec4b284abf4df5d6bf1c3852dbbf053c1b-image.png)

# 解法二：
helper函数返回以root为终点的最长路径以及root子树中的最长路径
以此来递归计算
```C++ []
class Solution {
public:
    pair<int, int> helper(TreeNode* root) {
        if (root == NULL) return {0, INT_MIN};
        if (root->left == NULL && root->right == NULL) {
            return {root->val, root->val};
        }
        auto l = helper(root->left);
        auto r = helper(root->right);
        int pl = max(l.first, 0);
        int pr = max(r.first, 0);
        int sl = l.second;
        int sr = r.second;
        int p = max(pl, pr) + root->val;
        int s = max(pl + pr + root->val, max(sl, sr));
        return {p, s};
    }
    int maxPathSum(TreeNode* root) {
        auto p = helper(root);
        return p.second;
    }
};
```
![image.png](https://pic.leetcode-cn.com/3e16c5da5491d00d9085b5ea84fafbfc7bbc483510612cae087a1d580651f3ec-image.png)
