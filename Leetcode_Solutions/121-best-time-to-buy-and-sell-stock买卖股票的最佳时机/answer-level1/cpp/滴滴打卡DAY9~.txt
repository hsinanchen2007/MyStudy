找出最小值和在其之后的最大值的差值
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0)
        {
            return 0;
        }
        int maxmoney = 0;
        int min = prices[0];
        for(int i = 1; i < len; i++)
        {
            int money = prices[i] - min;
            if(money < 0)
            {
                min = prices[i];
            }
            else if(money > maxmoney)
            {
                maxmoney = money;
            }
        }
        return maxmoney;
    }
};
```