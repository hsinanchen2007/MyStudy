

## 状态压缩dp

这是一个NP问题，数据范围比较小，可以用状态压缩去枚举所有状态

- dp[i][S]表示第i行状态为S的最大学生数
- S的取值为`[0, 1<<(n-1)]`
- 状态转换
  - `dp[i][s] = max(dp[i][s], dp[i-1][last] + cnt(s))` // s 和 last状态均为合法；cnt(s)表示状态s可以坐的学生数 

## 代码实现

```cpp
class Solution {
public:
    int cntS(int s){
        if (s == 0) return 0;
        return cntS(s & (s-1)) + 1;
    }
    int maxStudents(vector<vector<char>>& seats) {
        if (seats.empty() || seats[0].empty()) return 0;
        const int N = 1 << 8;
        const int m = seats.size(), n = seats[0].size();
        int dp[m][N];
        int status[m];
        memset(dp, 0, sizeof dp);
        memset(status, 0, sizeof status);
        for (int i = 0; i< m; i++)
            for (int j = 0; j < n; j++){ 
                status[i] <<= 1;
                if (seats[i][j] == '#') status[i] |= 1;
            }

        int ans = 0;
        for (int s = 0; s < (1<< n) ; s++){
            if ((s & (s << 1)) || (s & (s >>1))|| (s & status[0]) ) continue;
            dp[0][s] = max(dp[0][s], cntS(s));
        }
        for (int i = 1; i < m; i++) 
            for (int s = 0; s < (1<< n); s++){
                if ((s & (s << 1)) || (s & (s >>1))|| (s & status[i]) ) continue;
                for (int last = 0; last <(1<< n); last++){
                    if ((s & (last << 1)) || (s & (last >> 1))) continue;
                    dp[i][s] = max(dp[i][s], dp[i-1][last] + cntS(s));
                }
            }
        for (int s = 0; s <(1<<n); s++)ans = max(ans, dp[m-1][s]);
        return ans;
    }
};
```

[从零开始学算法](https://muyids.github.io/simple-algorithm)
