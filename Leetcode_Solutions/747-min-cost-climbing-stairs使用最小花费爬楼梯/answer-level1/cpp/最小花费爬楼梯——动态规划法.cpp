思路：动态规划

1.用一维数组来保存当前位置的总花费，dp[i]表示在第i个阶梯时总共要花费的体力值
2.若数组只有两个元素，直接返回最小花费的元素即可；
3.若cost.size()>2, 可以发现，dp[i]=min(cost[i]+dp[i-1],  cos[i]+dp[i-2]); 
4.上面可以这样理解：若当前为第i个阶梯，则只可能由处在第i-1阶梯上爬一步或在第i-2个阶梯上爬两步得来，那么，取上两步阶梯中花费累计值最小那个，加上当前阶梯的体力值，即为当前阶梯的累计花费最小值。
5.需要考虑初始值：
        dp[0] = cost[0];
        dp[1] = cost[1];
6.最后，如果当前已经处于最后一个阶梯或是倒数第二个阶梯，则爬一步或两步即可到顶部。因此，返回数组中最后两个元素中最小的那个值，即为总的最低花费。


题解：

```
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==2) return min(cost[0],cost[1]);
        int len = cost.size();
        int dp[len]={0};
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2;i!=len;++i){
            dp[i] = min(cost[i]+dp[i-1],cost[i]+dp[i-2]);
        }
        return min(dp[len-1],dp[len-2]);
    }
};
```
