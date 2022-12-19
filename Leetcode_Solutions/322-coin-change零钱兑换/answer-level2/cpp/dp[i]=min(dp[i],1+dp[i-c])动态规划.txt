
### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);//动态转移方程
        dp[0]=0;
        if(amount==0) return 0;
        if(amount<0) return -1;
        for(int i=0;i<=amount;i++){
            for(int c : coins){
                if(i-c<0) continue;
                else
                    dp[i]=min(dp[i],1+dp[i-c]);
            }
        }
        return dp[amount]==amount+1 ? -1:dp[amount];
    }
};
```