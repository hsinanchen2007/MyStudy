### 解题思路
与上一道题的区别是，这道题的最大收益方法就是：**遇到涨价的情况就赶紧抛售**。这样就算一直涨价，最终的总收益也和等待着最后抛售的收益一样。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int money=0,min=0x7ffffff;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min)
                min=prices[i];
            else if(prices[i]>min){
                money=money+prices[i]-min;
                min=prices[i];
            }
        }
        return money;
    }
};
```