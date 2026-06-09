### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
   int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        if (len < 2)
        {
            return 0;
        }
        if (len == 2)
        {
            int sum = (prices[len - 1] - prices[0] > 0) ? (prices[len - 1] - prices[0]) : 0;
            return sum;
        }
      
        vector<int> buys;
        int flag = 0;
        for (int i = 0; i < len; i++)
        {

            if ((i == 0 || prices[i - 1] >= prices[i]) && ((i + 1 < len) && prices[i] < prices[i + 1]) && (flag == 0 || flag == 2))
            {
                buys.push_back(prices[i]);
                flag = 1;
            }

            if (((i > 0) && prices[i - 1] <= prices[i]) && ((i == len - 1) || prices[i] > prices[i + 1]) && flag == 1)
            {
                buys.push_back(prices[i]);
                flag = 2;
            }
        }
        if (flag == 1)
        {
            buys.pop_back();
        }
        if (buys.size() < 2)
        {
            return 0;
        }
        if (buys.size() < 4)
        {
            int sum = (buys[1] - buys[0] > 0) ? (buys[1] - buys[0]) : 0;
            return sum;
        }
        int buyl1 = 0x7fffffff;
        int buyh1 = 0;
      
        int sum = 0;
        int slen = buys.size();
        int sum1 = 0;
        for (int i = 0; i < slen - 1; i+=2)
        {
           
            if (buys[i] < buyl1)
            {
                buyl1 = buys[i];
            }

            if (buys[i + 1] - buys[i] > sum1)
            {
                sum1 = buys[i + 1] - buys[i];
                buyh1 = i + 1;
            }

            if (buys[i + 1] - buyl1 > sum1)
            {
                sum1 = buys[i + 1] - buyl1;
                buyh1 = i + 1;
            }
                  int buyl2 = 0x7fffffff;
                 int buyh2 = 0;
                  int sum2 = 0;
            for (int j = slen - 1; j > 0; j-=2)
            {
                
                if (buys[j] > buyh2)
                {
                    buyh2 = buys[j];
                }

                if (buys[j] - buys[j - 1] > sum2)
                {
                    sum2 = buys[j] - buys[j - 1];
                    buyl2 = j - 1;
                }

                if (buyh2 - buys[j - 1] > sum2)
                {
                    sum2 = buyh2 - buys[j - 1];
                    buyl2 = j - 1;
                }

                if (buyh1 < buyl2)
                {
                    int temps = sum1 + sum2;
                    if (sum < temps)
                    {
                        sum = temps;
                    }
                }
                else
                {
                    if (sum < sum1)
                    {
                        sum = sum1;
                    }
                    if (sum < sum2)
                    {
                        sum = sum2;
                    }
                }
            }
        }
        return sum;
    }
};
```