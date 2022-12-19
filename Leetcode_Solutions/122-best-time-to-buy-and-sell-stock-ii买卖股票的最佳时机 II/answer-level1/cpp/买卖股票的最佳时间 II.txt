### 解题思路
想到的是用贪心算法的思路，就是只要后一天的比前一天的大，我就在前一天买入，后一天卖出，局部最优，来达到总体最优，
所以贪心算法计算得到的就是所有正数的和，假如说不用贪心算法求解，两数之间的差可能是正数，可能是0，可能是负数，
也就是如果结果和中加入0的话，肯定没有贪心算法优，如果是加负数，也是，如果是越过了某个正数不加，其结果肯定也没有贪心算法
优，所以此题适合用贪心算法。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        for(int i=0; i<n-1; i++)
        {
            if(prices[i+1] > prices[i])
                res += (prices[i+1] - prices[i]);
        }
        return res;
    }
};
```