
```cpp
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int ans = 0;
        vector<vector<int>> mid(10, vector<int>(10, 0));
        int used[10] = {0};
        int dp = 0;
        used[0] = 1;
        mid[1][3] = 2;
        mid[3][1] = 2;
        mid[4][6] = 5;
        mid[6][4] = 5;
        mid[7][9] = 8;
        mid[9][7] = 8;
        mid[1][7] = 4;
        mid[7][1] = 4;
        mid[2][8] = 5;
        mid[8][2] = 5;
        mid[3][9] = 6;
        mid[9][3] = 6;
        mid[1][9] = 5;
        mid[9][1] = 5;
        mid[3][7] = 5;
        mid[7][3] = 5;
        function<void(int, int)> dfs = [&](int ind, int last){
            if (ind >= m) {
                dp++;
            }
            if (ind >= n) {
                return;
            }
            for (int i = 0; i < 9; i++) {
                if (!used[i + 1] && used[mid[i + 1][last]]) {
                    used[i + 1] = 1;
                    dfs(ind + 1, i + 1);
                    used[i + 1] = 0;
                }
            }
        };
        used[1] = 1;
        dfs(1, 1);
        ans += dp * 4;
        dp = 0;
        used[1] = 0;
        used[2] = 1;
        dfs(1, 2);
        ans += dp * 4;
        dp = 0;
        used[2] = 0;
        used[5] = 1;
        dfs(1, 5);
        ans += dp;
        return ans;
    }
};
```