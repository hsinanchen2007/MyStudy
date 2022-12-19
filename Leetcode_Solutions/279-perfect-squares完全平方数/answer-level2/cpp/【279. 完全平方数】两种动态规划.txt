## 思路：动态规划
可以类比零钱兑换，这里将完全平方数看作可以用的零钱的。

### 代码
```c++
class Solution {
public:
    int numSquares(int n) {
        vector<int> res(n + 1, INT_MAX);
        res[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                res[i] = min(res[i], res[i - j * j] + 1);
            }
        }
        return res[n];
    }
};
```

#### 另一种写法
每次增加一个dp值
```c++
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(1, 0);
        while (dp.size() <= n) {
            int cnt = INT_MAX;
            int m = dp.size();
            for (int i = 1; i * i <= m; ++i) {
                cnt = min(cnt, dp[m - i*i] + 1);
            }
            dp.push_back(cnt);
        }
        return dp[n];
    }
};
```




