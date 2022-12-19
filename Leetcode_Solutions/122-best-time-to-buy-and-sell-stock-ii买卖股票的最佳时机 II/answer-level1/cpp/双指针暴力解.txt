### 解题思路
双指针，i为慢指针，j为快指针，只要i的值小于j的值就完成买卖。否则i，j同时后移

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int i=0,j=1,sum=0;
    if(prices.size()==0)return 0;
    while(j<prices.size())
    {
        
        if(prices[i]>=prices[j]){
            i++;
            j++;
        }
        else
        {
            sum=sum+(prices[j]-prices[i]);
            i++;
            j++;
        }
    }
    return sum;
    }
};
```
本题虽说不能同一天进行买和卖操作，但是连续增长时，多次买卖和一次完成峰谷值的相减得到的答案是一样的


