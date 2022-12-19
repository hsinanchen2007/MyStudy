这个题显然可以用递归的方式来做。但递归（不做 memorization）的做法时间复杂度比较高，应该是指数级别的。

如果用动态规划，时间复杂度会好一些，O(n^5)，嗯，真棒。

```c++
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        
        typedef vector<TreeNode*> Nodes;

        // dp 的 size 是 (n+2）* (n+2)。
        // 其中，第一行 dp[0] 是空的，因为我们不考虑 n = 0 的情况。
        // 此外，我们只会用到右上部分，包括从左上到右下的对角线。
        // dp[i][j] 的含义是：从 i 到 j，（不含j），可以生成哪些子树。
        // 假如 i = 2, j = 5，欲求 dp[2][5]，我们需要分别以 2,3,4 作为根节点。
        // 以 2 为根节点时，左边的子树来自于 dp[i][2]，右边来自于 dp[2+1][j]。
        // 把两边一一组合，就得到了以 2 为根节点的子树。3，4 同理。
        vector<vector<Nodes>> dp(n+2, vector<Nodes>(n+2, vector<TreeNode*>() ) );

        for (int i = n+1; i > 0; --i) {
            for (int j = i; j < n+2; ++j) {
                Nodes& nodes = dp[i][j];
                if (i == j) {
                    // 对角线上的都是 {nullptr}.
                    nodes.push_back(nullptr);
                } else if (i + 1 == j) {
                    // 紧贴对角线的都是叶子节点。
                    nodes.push_back(new TreeNode(i));
                } else {
                    // 分别尝试 [i, j) 作为 root，根据 dp 获取左右候选子树，一一组合。
                    for (int k = i; k < j; ++k) {
                        Nodes& left = dp[i][k];
                        Nodes& right = dp[k+1][j];
                        for (TreeNode* l : left) {
                            for (TreeNode* r : right) {
                                TreeNode* root = new TreeNode(k);
                                root->left = l;
                                root->right = r;
                                nodes.push_back(root);
                            }
                        }
                    }
                }
            }
        }
        return dp[1].back();
    }
};
```
