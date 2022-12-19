### 解题思路
##1. 动态规划
dp[i]表示构成金额i需要的最少硬币数量

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;

        for(int i=1;i<=amount;i++)
        {
            for(auto c:coins)
            {
                if(i-c>=0)
                {
                    if(dp[i-c]==INT_MAX)
                        continue;
                    else
                        dp[i]=min(dp[i],dp[i-c]+1);
                }
                    
            }
        }

        return dp[amount]!=INT_MAX?dp[amount]:-1;

    }
};
```
##2. 回溯+剪枝
1.从面额大的硬币开始拼凑，面额越大，一般来说需要的个数越少，但是也有例外，比如说amount=10，coins={1，5，7}，那么amount=7+1+1+1=5+5，所以还得对面额小的进行计算
2. 剪枝：如果当前硬币个数k+之前的硬币数count<前一轮凑得amount的硬币数，则进行递归，否则跳过；
```
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if(coins.size()==0 || amount==0)
            return 0;
        int res=INT_MAX;
        //从硬币面额大的开始拼凑；
        sort(coins.rbegin(),coins.rend());
        coin(coins,0,amount,res,0);
        return res==INT_MAX?-1:res;

    }

    void coin(vector<int>& coins,int index, int amount,int & res,int count)
    {
        if(amount==0)
        {
            res=min(res,count);
            return;
        }
        if(coins.size()==index)
            return;


        for(int k=amount/coins[index];k>=0 && k+count<res;k--)
        {
            coin(coins,index+1,amount-k*coins[index],res,count+k);
        }
        return;

    }
};
```