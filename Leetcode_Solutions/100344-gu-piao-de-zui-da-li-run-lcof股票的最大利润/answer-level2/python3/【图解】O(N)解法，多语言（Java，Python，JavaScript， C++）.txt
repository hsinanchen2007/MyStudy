## 思路

如果采用暴力法的话，我们只需要双层循环固定两个点，后面的点作为卖点，前面的点作为买点，我们返回差值的最大值即可，这种算法的时间复杂度为$O(N^2)$，我们考虑优化。

由于我们是想获取到最大的利润，我们的策略应该是低点买入，高点卖出。

由于题目对于交易次数有限制，只能交易一次，因此问题的本质其实就是求波峰浪谷的差值的最大值。

用图表示的话就是这样：

![](https://pic.leetcode-cn.com/75fcd9f615136fc12324c8e0b37ecf26f13b9f181ddbf44b11220bbf2d24be4c.jpg)

## 关键点解析

- 这类题只要你在心中（或者别的地方）画出上面这种图就很容易解决

## 代码

语言支持：JS，Python，C++，Java

JS Code:

```js
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let min = prices[0];
    let profit = 0;
    // 7 1 5 3 6 4
    for(let i = 1; i < prices.length; i++) {
        if (prices[i] > prices[i -1]) {
            profit = Math.max(profit, prices[i] - min);
        } else {
            min = Math.min(min, prices[i]);;
        }
    }

    return profit;
};
```



Python Code:

```python
class Solution:
    def maxProfit(self, prices: 'List[int]') -> int:
        if not prices: return 0

        min_price = float('inf')
        max_profit = 0

        for price in prices:
            if price < min_price:
                min_price = price
            elif max_profit < price - min_price:
                max_profit = price - min_price
        return max_profit
```

C++ Code:
```c++
/**
 * 系统上C++的测试用例中的输入有[]，因此需要加一个判断
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        auto min = prices[0];
        auto profit = 0;
        for (auto i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i -1]) {
                profit = max(profit, prices[i] - min);
            } else {
                min = std::min(min, prices[i]);;
            }
        }
        return profit;
    }
};
```

Java Code:

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length < 1) return 0;
        int min = prices[0];
        int res = 0;
        for(int i = 1; i < prices.length;i++) {
            if (prices[i] < min) min = prices[i];
            if (prices[i] - min > res) res = prices[i] - min;
        }
        return res;
    }
}
```


**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(1)$

## 相关题目

- [122.best-time-to-buy-and-sell-stock-ii](https://github.com/azl397985856/leetcode/blob/master/problems/122.best-time-to-buy-and-sell-stock-ii.md)
- [309.best-time-to-buy-and-sell-stock-with-cooldown](https://github.com/azl397985856/leetcode/blob/master/problems/309.best-time-to-buy-and-sell-stock-with-cooldown.md)

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)