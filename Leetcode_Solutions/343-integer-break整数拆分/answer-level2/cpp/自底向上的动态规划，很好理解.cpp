### 解题思路
![批注 2020-03-11 160758.jpg](https://pic.leetcode-cn.com/fd08ac5320a922acca35453fbf5abe924a0de4d77d6351b3fce503a349d5fc68-%E6%89%B9%E6%B3%A8%202020-03-11%20160758.jpg)

思路比较简单，具体看代码即可。

### 代码

```cpp
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i; j++){
                int t = max(max(dp[j]*dp[i-j], max(dp[j]*(i-j), j*dp[i-j])), j*(i-j));
                dp[i] = max(dp[i], t);
            }
        }
        return dp[n];
    }
};
```