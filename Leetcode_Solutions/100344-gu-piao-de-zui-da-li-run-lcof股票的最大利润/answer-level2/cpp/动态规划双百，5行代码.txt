**解题思路：**

第一次写，盈利和亏损的英文懒得查了--,用中文将就着看，感觉最高赞说的动态规划很清楚，但实在有些啰嗦，自己看完总结一下的方法。双百。



**代码**

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)//这种情况无法交易，返回0
            return 0;
        
        int ying=0,kui=-prices[0];//初始化盈利和亏损的状态方程
        for(int i=1;i<prices.size();i++)
        {
            ying=max(ying,kui+prices[i]);/*盈利状态转移，从第二天开始盈利的状态为
max(前一天的盈利状态，前一天亏损(因为购买了股票肯定要“亏损”)加上今天如果卖出去的价格))*/
            kui=max(kui,-prices[i]);//亏损状态转移，亏损越少越好。

        }
        return ying;
    }
};
```

