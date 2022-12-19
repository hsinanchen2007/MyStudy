输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1

dp[i] 用来存放每个数额少的硬币数；
dp[11] = min(dp[10],dp[9],dp[6])+1;（选1元硬币，之后就转化为10元钱怎么兑换零钱）
所以我们可以先将dp[1]-dp[10]求出来。

初始化0元需要0个硬币；
如果数额i<硬币面值coins[j]，用coins[j]或大于coins[j]的硬币都凑不出i，无解
如果数额i>=硬币面值coins[j]，就转化为求兑换i-coins[j]最少的硬币数，如果i-coins[j]凑不出来就直接跳过

```
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());    //先对硬币面值排序
        vector<int> dp(amount+1);//每个数额最少的硬币数
        int n = coins.size();
        dp[0] = 0;  //0使用0个硬币
        for(int i=1;i<=amount;i++){
            int minn = INT_MAX; //先初始化最少硬币数为INT_MAX
            for(int j=0;j<n;j++){   //遍历硬币面值数组
                if(i-coins[j]<0) break; //数额小于硬币结束
                //dp[i] = dp[i-coins[j]] + 1
                else if(dp[i-coins[j]]==INT_MAX) continue;  //i-coins[j]凑不出来
                else{
                    int temp = dp[i-coins[j]]+1;
                    if(temp<minn) minn = temp;
                }
            }
            dp[i] = minn;
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
```
