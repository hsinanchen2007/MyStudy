`dp[node][i][j]`代表当前节点node的父节点放置摄像头的状态为`i`（`1`为放置摄像头，`0`为不放置），自身放置摄像头的状态为`j`（`1`为放置摄像头，`0`为不放置）的情况下的最优解。
对于不可能的状态初始化值为`INF`。
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
    const int INF = 1e8;
    map<TreeNode*, vector<vector<int> > > dp;
    void init(TreeNode* root) {
        if (root == NULL) return;
        dp[root] = {{-1, -1}, {-1, -1}};
        init(root->left);
        init(root->right);
    }
    int dfs(TreeNode* root, int parent_place, int place) {
        if (dp[root][parent_place][place] != -1) {
            return dp[root][parent_place][place];
        }
        if (root != NULL && root->left == NULL && root->right == NULL) {
            dp[root][0][1] = 1;
            dp[root][1][1] = 1;
            dp[root][1][0] = 0;
            dp[root][0][0] = INF;
            return dp[root][parent_place][place];
        }
        int l00 = dfs(root->left, 0, 0);
        int l01 = dfs(root->left, 0, 1);
        int l10 = dfs(root->left, 1, 0);
        int l11 = dfs(root->left, 1, 1);
        int r00 = dfs(root->right, 0, 0);
        int r01 = dfs(root->right, 0, 1);
        int r10 = dfs(root->right, 1, 0);
        int r11 = dfs(root->right, 1, 1);
        dp[root][0][0] = min(l01 + min(r00, r01), r01 + min(l00, l01));
        dp[root][0][1] = 1 + min(l10, l11) + min(r10, r11);
        dp[root][1][1] = 1 + min(l10, l11) + min(r10, r11);
        dp[root][1][0] = min(l00, l01) + min(r00, r01);
        return dp[root][parent_place][place];
    }
    int minCameraCover(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        dp[NULL] = {{0, INF}, {0, INF}};
        init(root);
        dfs(root, 0, 0);
        return min(dp[root][0][0], dp[root][0][1]);
    }
};
```
效率不高，算是一种参考解法
![image.png](https://pic.leetcode-cn.com/4e788ed8ba259929fa325662b45de6aacce7a49fea235e9f9b6e32b622e89197-image.png)
