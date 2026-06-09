### 解题思路

自底向上的思路，根据字符串的长度L，从小到大动态规划：

1. 当 L <= 3时， L + 3 >= 2 * L，缩写不会使原字符串变短；
2. 当 L > 3 时，缩写有可能使原字符串变短，如果能找出不超过L的循环子串，我们从索引1开始找；
3. 如果 L > 3，并且没有长度小于L的循环子串，那么可以从最优子结构入手，枚举分裂字符串为两个子串的位置 k， k = i ~ i + L - 1，看是否子串的长度之和能够Relax整个子串的最优长度。

### 代码

```cpp
class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n+1, vector<string>(n+1));
        
        for(int L=1; L<=n; L++) {
            for(int i=0; i+L-1<n; i++) {
                int j = i + L - 1;
                string sub = s.substr(i, L);
                if(L <= 4) {
                    dp[i][j] = sub;
                } else {
                    string expand = sub + sub;
                    size_t idx = expand.find(sub, 1);
                    if(idx != string::npos && idx < L)
                        dp[i][j] = to_string(L / idx) + "[" + dp[i][i + idx - 1] +"]";
                    else {
                        dp[i][j] = sub;
                        for(int k=i; k<=j; k++) {
                            if(dp[i][k].length() + dp[k+1][j].length() < dp[i][j].length())
                                dp[i][j] = dp[i][k] + dp[k+1][j];
                        }
                    }
                }
            }
        }
        
        return dp[0][n-1];
    }
};
```