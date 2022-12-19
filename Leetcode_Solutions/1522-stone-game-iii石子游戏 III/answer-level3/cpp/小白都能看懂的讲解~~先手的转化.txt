动态规划问题最关键的在于能够由后一状态推导出前面的状态
这里我们设dp[i]为在i位置先手能够赢后手的最大分数
**最关键的状态转换在于先手取完之后，由于每次两人都采取**
**最优策略，之前的先手在取完之后变成了后手，之前的后手**
**在等待对方取完之后变成了先手，所以后续的dp[j]由之前先手在j位置**
**能够赢后手的最大分数变成了现在的后手能够赢取的最大分数**

设取一个为sum1,取两个为sum2,取三个为sum3
dp[i] = max(sum1-dp[i+1],sum2-dp[i+2],sum3-dp[i+3]);
现在这次能取得的分数减去对方之后先手能够取得的最大分数
代码如下
```
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int  dp[stoneValue.size()+1];
        fill(dp,dp+stoneValue.size()+1,INT_MIN);
        int  len = stoneValue.size();
        dp[len] = 0;
        for(int  i=len;i>=0;i--)
        {
            int  sum = 0;
            for(int  j=i;j<i+3&&j<len;j++)
            {
                sum = sum+stoneValue[j];
                //分别计算sum1,sum2,sum3
                dp[i] = max(dp[i],sum-dp[j+1]);
                //利用递推公式dp[i] = max(sum1-dp[i+1],sum2-dp[i+2],sum3-dp[i+3]);
            }
        }
        if(dp[0] > 0)
        {
            return  "Alice";
        }
        else  if(dp[0] == 0)
        {
            return  "Tie";
        }
        else  
        {
            return  "Bob";
        }
    }
};
```
最后，讲解不易，麻烦各路大佬左下角点个赞吧~~