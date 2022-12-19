### 解题思路
记忆化搜索，一行结束

### 代码

```cpp
class Solution {
public:
int dp[101]={1,1,2};
    int numWays(int n) {
        return dp[n]?dp[n]:(dp[n] = ((numWays(n-1)+numWays(n-2))%(1000000007)));
    }
};
```