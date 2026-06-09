## 思路:

动态规划，两种方法实现，但是`dp[i][k]`都是表示到数组第`i`为底公差为`k`的超过长度`3`的个数

思路一：直接转移方程

`dp[i][k]  += 1 + dp[j][k], j < i` 

思路二：记录元素的索引号

这样我们可以算出公差 `k = A[i] - A[j]`，找`A[j] - d`元素有几个(这里都是组成3个公差的个数)，在加上`A[j][k]`的个数就是`A[i][k]`

## 代码:

思路一：

```python
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        from collections import defaultdict
        dp = [defaultdict(int) for _ in range(len(A))] 
        res = 0
        for i in range(len(A)):
            for j in range(i):
                diff = A[i] - A[j]
                dp[i][diff] += dp[j][diff] +  1
                # 说明满足长度大于等于3
                if diff in dp[j]:
                    res += dp[j][diff]
        return res
```

思路二：

```python
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        from collections import defaultdict
        import bisect
        n = len(A)
        lookup = defaultdict(list)
        dp = [defaultdict(int) for _ in range(n)]
        res = 0
        # 记录每个元素的位置
        for idx, val in enumerate(A):
            lookup[val].append(idx)
        for i in range(n):
            for j in range(i):
                diff = A[i] - A[j]
                target = A[j] - diff
                # 先找 和 A[j], A[i]组成三个数组个数
                # for idx in lookup[target]:
                #     if idx < j:
                #         dp[i][diff] += 1
                #     else:
                #         break
                dp[i][diff] += bisect.bisect_left(lookup[target], j) # 可以用二分找个数
                # 加上 第j位置公差为diff个数
                dp[i][diff] += dp[j][diff]
            # 统计个数
            for val in dp[i].values():
                res += val
        return res
```

