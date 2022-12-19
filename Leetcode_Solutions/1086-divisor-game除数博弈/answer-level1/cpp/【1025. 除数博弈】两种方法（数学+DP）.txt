### 思路一：找规律
偶数赢，奇数输

### 代码
时间复杂度：O(1)
```cpp
class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};
```

### 思路二：动态规划
dp[N]和dp[N - x]中一个为真一个为假，对于x的取值为(1, N)，对于每一个x值，如果存在dp[N - x]为false并且i % x == 0，则dp[i]为true，否则为false。
### 代码
```c++
class Solution {
public:
    bool divisorGame(int N) {
        if (N < 2) return false;
        vector<int> dp(N + 1);
        dp[1] = false;
        dp[2] = true;
        for (int i = 3; i <= N; ++i) {
            dp[i] = false;
            for (int j = 1; j < i; ++j) {
                if (i % j == 0 && dp[i - j] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};
```
