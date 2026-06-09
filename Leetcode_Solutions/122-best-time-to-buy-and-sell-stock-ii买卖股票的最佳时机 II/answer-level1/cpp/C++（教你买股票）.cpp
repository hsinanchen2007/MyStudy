### 解题思路
此处撰写解题思路
分析这个题目的特点：例如[7,1,2,3,4,5,3,5,6,4]
先找到一个 ***升序*** 的数列，此处为1,2,3,4,5，那么当股票为1的时候买入，当股票价格涨到最高5则抛出.
（即：股票价格最低时买入，涨价到最高（开始降价前）抛出，然后立即买入下一股）
再重复前面的步骤

**** 代码注释比较生动，不看会后悔哦！！！****
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int size = prices.size();
        int sum_profit = 0; //总利润（装钱的“大包”）
        int min_price = INT_MAX; //相对最低售价（每一个升序数列中最小的）
        int max_profit = 0; //最高利润（装钱的“小包”）
        
        min_price = min(min_price, prices[0]); //首先假定买入第一股

        for(int i = 1; i < size; i++)
        {
            if(prices[i] < prices[i-1]) //判断是否买入（即是否开始降价）
            {
                min_price = prices[i]; //更新买入的股票
                sum_profit += max_profit; //在购入下一股时，将赚的钱装进“大包”里
                max_profit = 0; //将“小包”清空，再拿去装钱
            }
            else if(prices[i] > prices[i-1]) //更新最大利润（如果股票价格一直涨，就一直增加）
            {
                int profit = prices[i] - min_price; //计算此时卖出能赚多少钱
                max_profit = max(profit, max_profit); //和上一次卖出相比，哪个赚的多？
            }
        }

        if(max_profit != 0) //将最后一股赚的钱加进去（不过可能没赚到、、、）
            sum_profit += max_profit;

        return sum_profit;      
    }
};
```