## 思路

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```cpp
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }
        return dp[n];
    }
};
```

### 优化空间
因为当前数只和前两个数有关，所以可以用两个变量只保留前两个数。

时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int a = 0, b = 1, res = 0;        
        for (int i = 2; i <= n; ++i) {
            res = (a + b) % 1000000007;
            a = b;
            b = res;        
        }
        return res;
    }
};
```


