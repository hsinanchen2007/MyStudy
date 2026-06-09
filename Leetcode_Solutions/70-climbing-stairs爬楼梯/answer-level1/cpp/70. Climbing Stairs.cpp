### 解题思路
递归+记忆化搜索

### 代码

```cpp
class Solution {
public:
    //dp[i]: 前i个梯子有多少种方法
    //dp[i] = dp[i-1] + dp[i-2]
    //用递归的话，将dp[i]转化为递归函数climbStair()
    //转化为递归函数climbStair(i) = climbStair(i-1) + climbStair(i-2)
    int climbStairs(int n) {
        if(memo.count(n)){
            return memo[n];
        }
        if(n == 0 || n == 1){
            return 1;
        }
        else{
            memo[n] = climbStairs(n-1) + climbStairs(n-2);
            return memo[n];
        }
    }

private:
    map<int, int> memo;
};
```

### 解题思路
一维状态表达式的动态规划

### 代码

```cpp
class Solution {
public:
    //dp[i]: 前i个梯子有多少种方法
    //dp[i] = dp[i-1] + dp[i-2]
    int climbStairs(int n) {
        int dp[n+1] = {0};
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
```