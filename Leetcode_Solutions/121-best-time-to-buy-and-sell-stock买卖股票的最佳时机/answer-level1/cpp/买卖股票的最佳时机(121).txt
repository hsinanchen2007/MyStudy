### 解题思路
一次遍历：在最低点买入股票，之后每一天都计算如果今天卖出能赚多少钱。遇到更好的收益就更新最大值，遇到更低的点就更新最小值，遍历数组得到最佳收益。时间复杂度O(n), 只需遍历一次；空间复杂度O(1),只使用了常数个变量。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=1e9, maxprice=0;
        for(int i=0;i<prices.size(); i++){
            maxprice=max(maxprice, prices[i]-minprice);
            minprice=min(minprice, prices[i]);
        }
    return maxprice;
    }
};
```