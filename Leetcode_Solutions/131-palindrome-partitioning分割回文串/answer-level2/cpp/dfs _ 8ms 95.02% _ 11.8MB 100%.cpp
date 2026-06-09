### 解题思路
1. 动态规划提前计算回文子串
2. dfs搜索的时候注意剪枝, 直接根据DP表取是否为回文串, 效率更高
3. 传参尽量传引用, 可以大幅提高效率节省空间

![1.png](https://pic.leetcode-cn.com/79861ffeb9ad8c627566a682f094fd73be711a58d70aa818cf9a5d6bfcb31e45-1.png)


### 代码

```cpp
class Solution {
public:
    vector<vector<string>> res;
    int length = 0;
    vector<vector<bool>> dp;

    vector<vector<string>> partition(string s) {
        // 1. 动态规划算回文子串  2. dfs搜分割方案
        length = s.size();
        dp.resize(length, vector<bool>(length, false));
        // dp[i][j]表示s[i: j + 1]是否是回文串
        for (int len = 0; len < length; len++) {
            for (int i = 0; i + len < length; i++) {
                if (len == 0) {
                    dp[i][i + len] = true;
                    continue;
                }
                if (s[i] == s[i + len] && (len == 1 || dp[i + 1][i + len - 1])) {
                    dp[i][i + len] = true;
                }
            }
        }
        vector<string> path;
        dfs(s, 0, path);
        return res;
    }
    
    void dfs(const string& s, const int& idx, vector<string>& path) {
        if (idx >= length) return;

        for (int i = idx; i < length; i++) {
            if (dp[idx][i]) {
                path.push_back(s.substr(idx, i - idx + 1));
                if (i == length - 1) {
                    res.push_back(path);
                    path.pop_back();
                    return;
                }
                dfs(s, i + 1, path);
                path.pop_back();
            }
        }
    }
};
```