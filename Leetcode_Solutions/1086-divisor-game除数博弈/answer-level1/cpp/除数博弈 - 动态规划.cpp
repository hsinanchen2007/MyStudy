### 解题思路
参考用户@PandaWaKaKa的实现：
1. 若当前数字i的公约数里面有输掉的情况（相当于让对方输），那么当前拿到数字i的玩家就能赢，否则输！


### 代码

```cpp
class Solution {
public:

    bool divisorGame(int N) {
        if(N == 1) return false;
        int dp[N+1];
        memset(dp, 0, sizeof(dp));
        dp[2] = 1;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j < i / 2; j++){
                if(i % j == 0 && dp[i-j] == 0){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[N] == 1;   
    }
};
```