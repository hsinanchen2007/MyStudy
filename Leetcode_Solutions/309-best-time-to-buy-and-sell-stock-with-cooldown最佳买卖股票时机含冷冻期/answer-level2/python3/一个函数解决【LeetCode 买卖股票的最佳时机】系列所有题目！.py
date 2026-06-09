> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/b886d9662d355f469ffc580268d364e6a05cddab681e49e9163376b99d4d2542-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)

## 题目和题解汇总
【LeetCode 买卖股票的最佳时机】系列一共六道题目，这里把我自己的题解还有题目链接汇总一下，方便大家查找。

### 第一题
[LeetCode 121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/ "LeetCode 121. 买卖股票的最佳时机")  
[每日算法系列【LeetCode 121】买卖股票的最佳时机](https://zhuanlan.zhihu.com/p/108895299 "每日算法系列【LeetCode 121】买卖股票的最佳时机")

### 第二题
[LeetCode 122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/ "LeetCode 122. 买卖股票的最佳时机 II")  
[每日算法系列【LeetCode 122】买卖股票的最佳时机 II](https://zhuanlan.zhihu.com/p/108902700 "每日算法系列【LeetCode 122】买卖股票的最佳时机 II")

### 第三题
[LeetCode 123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/ "LeetCode 123. 买卖股票的最佳时机 III")  
[每日算法系列【LeetCode 123】买卖股票的最佳时机 III](https://zhuanlan.zhihu.com/p/108908636 "每日算法系列【LeetCode 123】买卖股票的最佳时机 III")

### 第四题
[LeetCode 188. 买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/ "LeetCode 188. 买卖股票的最佳时机 IV")  
[每日算法系列【LeetCode 188】买卖股票的最佳时机 IV](https://zhuanlan.zhihu.com/p/108925381 "每日算法系列【LeetCode 188】买卖股票的最佳时机 IV")

### 第五题
[LeetCode 714. 买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/ "LeetCode 714. 买卖股票的最佳时机含手续费")  
[每日算法系列【LeetCode 714】买卖股票的最佳时机含手续费](https://zhuanlan.zhihu.com/p/108930022 "每日算法系列【LeetCode 714】买卖股票的最佳时机含手续费")

### 第六题
[LeetCode 309. 最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/ "LeetCode 309. 买卖股票的最佳时机")  
[每日算法系列【LeetCode 309】最佳买卖股票时机含冷冻期](https://zhuanlan.zhihu.com/p/108931927 "每日算法系列【LeetCode 309】最佳买卖股票时机含冷冻期")

## 通用解法
上面六道题目中，前四题限制了买卖的次数，第五题加入了手续费，第六题加入了冻结时间。所以我们提出一般性的问题：

**给定每天的价格 $prices$，最大买卖次数 $k$，手续费 $fee$，冻结时间 $freeze$，求最大利润。**

观察前面六题的代码，我们可以在第四题基础上进行修改，这样代码量比较小。

首先是增加手续费，这个很简单，只需要在 $dp1$ 更新时减去一个手续费 $fee$ 就行了。

有点麻烦的是冻结时间。在第六题代码中，增加了一个维度用来保存每一只股票之前（包含）的最大利润，目的是为了获取相隔一个冻结时间之前的股票以前可以获得的最大利润。但是通用情况下不能这么保存，不然的话空间复杂度就变成了 $O(nk)$ ，极限情况下会爆掉。

解决方法就是，因为对于第 $i$ 只股票来说，只需要访问它与 $dp1[i-freeze-1]$ 之间的数值，那么我们只需要保存 $freeze + 1$ 大小的数组就行了。在访问的时候，采用取模的方法，来让数组滚动起来。

还有一些细节，比如如果 $k \ge n / 2$，那么问题就退化为了没有买卖次数限制，也就是第五题和第六题的情况。如果不这样处理的话，按照上面方法做，时间复杂度和空间复杂度都是 $O(nk)$ ，可能会吃不消。

## 代码
### 通用函数
```python
class Solution:
    def solve(self, prices, k=1, fee=0, freeze=0):
        n = len(prices)
        if n == 0 or k == 0: return 0
        limit = 0 if k >= n//2 else 1
        k = 1 if k >= n//2 else k
        dp0 = [-prices[0]] * (k+1)
        dp1 = [[0]*(k+1) for _ in range(freeze+1)]
        for i in range(1, n):
            for j in range(1, k+1):
                dp0[j] = max(dp0[j], dp1[i%(freeze+1)][j-1 if limit else j]-prices[i])
                dp1[i%(freeze+1)][j] = max(dp1[(i-1)%(freeze+1)][j], dp0[j]+prices[i]-fee)
        return max(dp1[(n-1)%(freeze+1)][k], 0)
```

### 第一题
```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return self.solve(prices, k=1, fee=0, freeze=0)
```

### 第二题
```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return self.solve(prices, k=len(prices), fee=0, freeze=0)
```

### 第三题
```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return self.solve(prices, k=2, fee=0, freeze=0)
```

### 第四题
```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        return self.solve(prices, k, fee=0, freeze=0)
```

### 第五题
```python
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        return self.solve(prices, len(prices), fee, 0)
```

### 第六题
```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return self.solve(prices, k=len(prices), fee=0, freeze=1)
```