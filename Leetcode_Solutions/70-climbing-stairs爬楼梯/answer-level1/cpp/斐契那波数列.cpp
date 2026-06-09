### 解题思路
典型的dp，斐契那波数列
dp[n] = dp[n-1] + dp[n-2]
使用两个变量维护历史信息，这样就可以击败100%的用户

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n < 2) return 1;
        long dp0 = 1, dp1 = 1;
        for(int i = 1; i < n; ++i){
            long dp = dp0 + dp1;
            dp0 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};
```

### 结果
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 
内存消耗 : 5.8 MB , 在所有 C++ 提交中击败了 100.00% 的用户