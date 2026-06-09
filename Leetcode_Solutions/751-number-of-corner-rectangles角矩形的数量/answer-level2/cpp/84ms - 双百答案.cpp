```
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 1 || m == 1) return 0;
        int ans = 0;
        vector<int> valid;
        valid.reserve(max(n, m));
        if (n < m) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j]) {
                        valid.push_back(j);
                    }
                }
                for (int j = i + 1; j < n; j++) {
                    long cnt = 0;
                    for (int k = 0; k < valid.size(); k++) {
                        if (grid[j][valid[k]]) {
                            cnt++;
                        }
                    }
                    ans += (cnt * (cnt - 1)) >> 1;
                }
                valid.resize(0);
            }
        } else {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[j][i]) {
                        valid.push_back(j);
                    }
                }
                for (int j = i + 1; j < m; j++) {
                    long cnt = 0;
                    for (int k = 0; k < valid.size(); k++) {
                        if (grid[valid[k]][j]) {
                            cnt++;
                        }
                    }
                    ans += (cnt * (cnt - 1)) >> 1;
                }
                valid.resize(0);
            }
        }
        return ans;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```
