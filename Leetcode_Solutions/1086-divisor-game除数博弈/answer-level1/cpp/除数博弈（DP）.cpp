### 解题思路
- 动态规划
- dp[i]表示先手拿到数字i是否会赢。显然，dp[1] = false; dp[2] = true;
- 对于大于2的任意的一个数字i，如果在1~i-1之间存在一个数j，使得i能被j整除并且dp[i -j] = false，也就是说能够让BOB先手拿到 i - j 这个必输的数字，那么bob必输，Alice必赢
- 题目说双方都是最佳状态，那么只要存在上述的j，那么Alice一定会选它。如果不存在，那么Alice必输。

### 代码

```cpp
class Solution {
public:
    bool divisorGame(int N) {
        if(N == 1)  return false;
        if(N == 2)  return true;
        bool dp[N + 1];
        memset(dp, 0, sizeof(dp));
        dp[1] = false;
        dp[2] = true;
        for(int i = 3; i <= N; i++){
            for(int j = 1; j < i; j++){
                if(i % j == 0 && dp[i - j] == false){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};
```