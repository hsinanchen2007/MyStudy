### 解题思路
只要明天比今天贵，就进行买卖。

### 代码

```cpp
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int sum=0;
        int i=0;
        if(prices.size()<1) return 0;
        while(i<prices.size()-1)
        {
            if(prices[i]<prices[i+1])
            {
                sum+=(prices[i+1]-prices[i]);
            }
            ++i;
        }
        return sum;
    }
};
```