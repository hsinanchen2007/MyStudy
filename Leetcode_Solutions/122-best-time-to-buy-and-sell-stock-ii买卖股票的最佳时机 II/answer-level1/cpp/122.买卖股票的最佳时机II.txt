### 解题思路
序列分两种情况，有序和无序。
①对于有序的序列，我们采用后一天比前一天价格高就买卖的策略。
例如：1 2 3 4 
利润 = （2-1）+（3-2）+（4-3） = 4-1 = 3
虽然计算方法不符合题干要求的同一天不能买卖，但是可以发现最后的计算结果4-1 并不是同一天买卖
②对于无序的序列。
例如1 5 3 2 其实可以看出 无序可以拆成 有序（1 5） + 逆序（3 2） 逆序不交易（利润小于0）
有序部分还是按照①中的方法计算 。

综上所述：采取后一天比前一天价格高就买卖的策略计算就可以得到解。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)//special case
            return 0;
        int pro = 0;
        for(int i = 0; i < prices.size() - 1;i++)
        {
            if(prices[i+1]-prices[i] > 0)//后一天比前一天价格高就买卖
                pro += prices[i+1]-prices[i];
        }
        return pro;
    }
};
```