### 解题思路
采用dp的思想，存储子问题的解，避免重复计算

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(dp[n] != 0){
            // 如果子问题解存在，直接返回子问题的解
            return dp[n];
        }
        else{
            dp[n] = (fib(n - 1) + fib(n - 2)) % 1000000007;
            return dp[n];
        }
    }
private:
    int dp[101] = {0};  // 采用dp的思想，存储子问题的解，避免重复计算
};
```

### 优化内存 ###
每次计算只需要知道f(n-1)和f(n-2)的结果，所以这里只设两个状态
```
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        int dp[2] = {0, 1};     // dp[1]表示f(n-1)，dp[0]表示f(n-2)
        int result = 0;

        for(int i = 2; i <= n; ++i){
            result = (dp[0] + dp[1]) % 1000000007;  // f(n-1)+f(n-2)
            dp[0] = dp[1];  // 下一时刻f(n-2)为上一时刻的f(n-1)
            dp[1] = result;     // 下一时刻的f(n-1)为上一时刻的f(n)
        }
        return result;
    }

};
```