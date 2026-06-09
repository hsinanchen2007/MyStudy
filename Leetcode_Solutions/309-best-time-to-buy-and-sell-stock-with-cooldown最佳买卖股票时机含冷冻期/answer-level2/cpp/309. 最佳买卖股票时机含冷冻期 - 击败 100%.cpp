### 思路
每天可能存在三种状态：
- hold：继续持有股票
- sold：卖出股票
- rest：什么都不做

转换关系如下：
![image.png](https://pic.leetcode-cn.com/5a2b5cd5c164c831d802cd0865f6d00d4de8f308a9485359c44bbe31a71332a5-image.png){:width=250}

**sold：**
- 前一天hold，当日卖出股票

**hold：** 可由两个情况转换来
- 前一天hold，当日rest
- 前一天rest，当日买入股票变为hold

**rest：**
- 前一天sold，当日必须rest
- 前一天rest，当日继续rest

所以
- `sold[i] = hold[i-1] + price[i];`
- `hold[i] = max(hold[i-1], rest[i-1] - price[i])`
- `rest[i] = max(rest[i-1], sold[i-1])`

最后一天最大值情况为要么什么都不做，要么卖出股票，即 `max(sold，rest)`。

### 代码
```c++ [-C++]
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0, rest = 0, hold = INT_MIN;
        for (int p : prices) {
            int pre_sold = sold;
            sold = hold + p;
            hold = max(hold, rest - p);
            rest = max(rest, pre_sold);
        }
        return max(sold, rest);
    }
};
```
