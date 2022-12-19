执行用时 :8 ms, 在所有 C++ 提交中击败了84.54%的用户
内存消耗 :9.5 MB, 在所有 C++ 提交中击败了45.07%的用户

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //贪心策略，在价格极小值时买入，在价格极大值时卖出
        //极小值：第一个数且比第二个小；或中间的数，且比前一个后一个都小
        //极大值：最后一个数且比倒数第二个大；或中间的数，且比前一个后一个都大
        
        //特殊情况判定
        if(prices.size()<=1)
            return 0;
       
        int minPrice = prices[0];
        int maxPrice = prices[0];
        bool bought = false;
        int profit = 0;
        for(int i = 0; i<prices.size(); i++)
        {
            if(i == prices.size()-1)       //最后一个元素，特殊处理一下
            {
                if(bought)
                    profit += prices[i];
                break;
            }
            if(!bought)
            {
                if(prices[i] < prices[i+1] )
                {
                    profit -=prices[i];
                    bought = true;
                }
                continue;
            }
            if(bought)
            {
                if(prices[i]>=prices[i+1])
                {
                    profit += prices[i];
                    bought = false;
                }
                continue;
            }     
        }
        return profit;
    }
};
```
