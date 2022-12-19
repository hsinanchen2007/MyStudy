差分数组 diff[i] = prices[i+1] - prices[i];

差分数组的连续子区间和的值，就正好是原始股价数组进行一次交易的差价（后 - 前）。
这里就转换成了一个求最大子序和问题。

所列题解略去了差分数组，降低了空间复杂度。


```python3 []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        last, profit = 0, 0
        for i in range(len(prices)-1):
            last = max(0, last + prices[i+1] - prices[i])
            profit = max(profit, last)
        return profit
```


```c []
int max(int a, int b) {
    if(a > b){
        return a;
    } else {
        return b;
    }
}

int maxProfit(int* prices, int pricesSize){
    int last = 0, profit = 0;
    for (int i = 0; i < pricesSize - 1; ++i) {
        last = max(0, last + prices[i+1] - prices[i]);
        profit = max(profit, last);
    }
    return profit;
}
```


```rust []
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
    let mut last = 0;
    let mut profit = 0;
    for i in 0..(prices.len()-2) {
        last = max(0, last + prices[i+1] - prices[i]);
        profit = max(profit, last);
    }
      profit
    }
}

fn max(a: i32, b:i32) -> i32 {
    if (a > b) {
        a
    } else {
        b
    }
}
```

参考：
- [暴力枚举、动态规划、差分思想](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/bao-li-mei-ju-dong-tai-gui-hua-chai-fen-si-xiang-b/)
- [121. 买卖股票的最佳时机 - dp 7 行简约风格](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/121-mai-mai-gu-piao-de-zui-jia-shi-ji-dp-7-xing-ji/)