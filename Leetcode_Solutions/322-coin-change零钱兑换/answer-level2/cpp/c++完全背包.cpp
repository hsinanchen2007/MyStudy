### 解题思路
两重循环，完全背包的内层循环从0开始，状态转移方程看代码。

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int inf = 0x3f3f3f3f;
        int dp[10000005];
        for(int k=0;k<=amount;k++)dp[k]=inf;
        dp[0]=0;
        for(int i=0;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]<0);
                else
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        if(dp[amount]==inf)return -1;
        else return dp[amount];


    }
};
```