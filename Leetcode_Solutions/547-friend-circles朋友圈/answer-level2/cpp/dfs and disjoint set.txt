都是至少93%快的代码
```cpp
class Solution {
private:
    void dfs(int i, bool* vis, vector<vector<int>>& M) {
        vis[i] = true;
        for (int k = 0; k < M.size(); k ++) {
            if (!vis[k] && M[i][k])
                dfs(k, vis, M);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        vector<int> f(n);
        iota(f.begin(), f.end(), 0);
        function<int(int x)> find = [&](int x) {
            return x == f[x] ? x : f[x] = find(f[x]); 
        };
        for (int i = 0; i < M.size(); i ++)
            for (int j = 0; j < M[0].size(); j ++) {
                if (M[i][j]) {
                    int par_i = find(i);
                    int par_j = find(j);
                    if (par_i != par_j)
                        f[par_i] = par_j;
                }
            }
        int ans = 0;
        for (int i = 0; i < f.size(); i ++) 
            if (f[i] == i)
                ans ++;
        return ans;
    }
    // 时间复杂度: O(N^2)
    // 空间复杂度: O(N^2)
    int findCircleNum_dfs(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size(), ans = 0;
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i ++) 
            if (!vis[i]) {
                dfs(i, vis, M);
                ans ++;
            }
        return ans;
    }
};