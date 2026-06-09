这道题目可以通过数学推导转化成 01 背包问题。

可以把这堆石头分成左右两堆，分别令：

$$a_{x1}-a_{y1} \\ a_{x2}-a_{y2} \\...\\ a_{xn}-a_{yn}$$

然后其正负关系恰好可以抵消成最小值即可。

$$(a_{x1}+a_{x2}+...+ a_{xn})-(a_{y1}+...+a_{yn})$$

用 01 背包的角度来思考，其实就是将整堆石头背 `sum // 2` 即可。奇数的时候向下取整，余数及是无法抵消的部分。



```python
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        dp = [0 for _ in range(1005)]
        from functools import reduce
        s = reduce(lambda x, y: x + y, stones)
        W = s // 2
        for item in stones:
            for i in range(W, item - 1, -1):
                dp[i] = max(dp[i], dp[i - item] + item)
        return s - dp[W] * 2
```