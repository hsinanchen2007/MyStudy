### 解题思路
此处撰写解题思路
截止上一天（0~n-1），买进的价格总能找到最小的,
但卖出的价格不一定是最大的，有可能在第j天到最高价，但是买进价同样很大, [6,7,...1,4]
只要当天的收益(p[n]-buy_min)比上一次的收益大，这个结果就是可以接受的


### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto count = prices.size();
        if (count == 0)
        return 0;

        int sell = 0;
        int buy = 100000;
        int sell_day = 1;
        int buy_day = 0;
        int max = 0;

        for (auto i = 0; i < count - 1; ++i) {
            if (i + 1 < count && i < count - 1) {
                if (buy > prices[i]) {
                buy = prices[i];
                buy_day = i;
                }

                if (sell < prices[i + 1]) {
                    if (buy_day < i + 1) {
                        int delta = prices[i + 1] - buy;
                        if (max < delta) {
                            max = delta;
                        }
                        max = max > 0 ? max : 0;
                    }
                }
            }
        }

    return max;
    }
};
```