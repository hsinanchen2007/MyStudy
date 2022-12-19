解题思路：由于在同一天不能进行多项交易，对于连续增长的股票值一次交易比多次交易收益大，如[2,6,8,10]一次交易最大收益为8，多次交易最大收益为6；而对于不是连续增长的股票值多次交易比一次交易收益大，如[2,8,6,10]，一次交易最大收益为8，多次交易最大收益为10。
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0;
        for(int i=0;i<prices.size();i++)
        {
            int count=0;
            while(i<prices.size()-1&&prices[i+1]>prices[i])
            {
                count++;
                i++;
            }
            maxPro+=prices[i]-prices[i-count];
        }
        return maxPro;
    }
};
```
