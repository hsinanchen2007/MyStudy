### 解题思路
- 首先要判断数组元素是否为空，这个很重要，如果为空，即使提交的时候没问题，执行代码的时候也会出错；
- maxp:记录全局最大值
- m:记录价格最低的股票
(以上两个数字都会不断维护，不用纠结于初始值)

- 心得:全局最大值一直是解决本类问题的重点，它需要不断刷新。
### 代码

```cpp

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        return 0;
         int maxp=0;
         int m=prices[0];
         for(int i=0;i<prices.size();i++)
         {       
             maxp=max(maxp,prices[i]-m);//最大值=max((上一次的最大值)与(本次价格-最小价格))
             m=min(m,prices[i]);//刷新与维护最小值
         }
         return maxp;
    }
};
```