### 代码

```cpp
红黑树：
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        map<int, map<int, vector<int>>> helper;
        function<void(TreeNode*, int, int)> dfs = [&helper, &dfs](TreeNode* node, int x, int y) {
            if (node) {
                helper[x][y].push_back(node->val);
                dfs(node->left, x - 1, y + 1);
                dfs(node->right, x + 1, y + 1);
            }
        };
        dfs(root, 0, 0);
        for (auto& e : helper) {
            res.emplace_back();
            for (auto& f : e.second) {
                res.back().insert(res.back().end(), f.second.begin(), f.second.end());
            }
        }
        return res;
    }
};
数组排序（有深度限制，先统计多少元素可以规避深度限制）：
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<vector<int>> helper;
        function<void(TreeNode*, int, int, int, int)> dfs = [&helper, &dfs](TreeNode* node, int x, int y, int s, int t) {
            if (node) {
                int m = ((long)s + (long)t) / 2;
                helper.push_back({x, y, m, node->val});
                dfs(node->left, x - 1, y + 1, s, m);
                dfs(node->right, x + 1, y + 1, m, t);
            }
        };
        dfs(root, 0, 0, INT_MIN, INT_MAX);
        sort(helper.begin(), helper.end());
        int ind = INT_MIN;
        for (auto& e : helper) {
            if (e[0] != ind) {
                res.emplace_back();
                ind = e[0];
            }
            res.back().push_back(e[3]);
        }
        return res;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```