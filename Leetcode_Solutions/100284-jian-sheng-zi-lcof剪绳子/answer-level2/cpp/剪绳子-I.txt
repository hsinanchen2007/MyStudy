### 解题思路
这道题目用dfs递归会超时的
动态规划：
![image.png](https://pic.leetcode-cn.com/ffb1b9d1c72d475cc93b01b0eabf3b7bc69ce953ec1cdb29b424992c5c3cc260-image.png)


### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        int result = 0;
        int dp[59] = { 0 };
        dp[2] = 1;
        // 1 < m <= n
        for (int i = 3; i <= n; i++){
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i-j), j * dp[i-j]));
            }
        }
        return dp[n];
    }
};
```