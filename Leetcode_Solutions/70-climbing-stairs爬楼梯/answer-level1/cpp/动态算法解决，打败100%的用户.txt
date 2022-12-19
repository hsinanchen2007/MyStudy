### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(2);
        for(int i=3;i<=n;i++){
            dp.push_back(dp[i-1] + dp[i-2]);
        }
        return dp[n];
    }
};
```