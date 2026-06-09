思路一: `Kadane's Algorithm`参考[维基百科](https://zh.wikipedia.org/wiki/%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E5%88%97%E9%97%AE%E9%A2%98)

简单介绍一下,如果一个数组为`[a1, a2, a3, a4, a5]`,

`a5 - a1 = (a2 - a1) + (a3 - a2) + (a4 - a3) + (a5 - a4)`

所以,我们这一题就是找两个差值最大数!

```python [1]
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        cur_max = 0
        for i in range(1, len(prices)):
            # 记录目前位置以i为结束的, 差值最大值
            cur_max += (prices[i] - prices[i-1])
            # 如果 cur_max 小于0 说明要改变起始的位置
            cur_max = max(0, cur_max)
            res = max(res, cur_max)
        return res
```



```java [1]
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) return 0;
        int cur_max = 0;
        int res = 0;
        for (int i = 1; i < prices.length; i++) {
            cur_max += prices[i] - prices[i - 1];
            cur_max = Math.max(0, cur_max);
            res = Math.max(cur_max, res);
        }
        return res;
    }
}
```

思路二 : 动态规划,我们可以遍历数组,记录前面最小的价格,用当天价格减去最小价格,一定是这天可以获得最大利润!

```python [2]
def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        res = 0
        cur_min = prices[0]
        for i in range(1, len(prices)):
            res = max(res, prices[i] - cur_min)
            cur_min = min(cur_min, prices[i])
        return res
```


```java [2]
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) return 0;
        int res = 0;
        int pre_min = prices[0];
        for (int i = 1; i < prices.length; i++){
            res = Math.max(res, prices[i] - pre_min);
            pre_min = Math.min(pre_min, prices[i]);
        }
        return res;  
    }
}
```

