### 解题思路
假设dp[i][j] 表示用i种硬币凑到J块钱的最少硬币上数
首先 我们来看看dp[i][j] 怎么来的
对于第i种硬币 我们有两种选择 
不选第i种硬币，那就是求用i-1种硬币凑到j块钱的最少硬币数
选第i种硬币，那就是求用i种硬币凑到j-coins[i]块钱的最少硬币数

#### 状态转移方程
dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i]]+1)

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size=coins.size();
        int dp[20][10000]={0};
        for(int i=1;i<=amount;i++) dp[0][i]=10000;
        for(int i=1;i<=size;i++){
            for(int j=1;j<=amount;j++){
                
                if(j>=coins[i-1]) 
                dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                else
                dp[i][j]=dp[i-1][j];
                
                
            }
        }
        if(dp[size][amount]==10000) return -1;
        else return dp[size][amount];
        

    }
};
```