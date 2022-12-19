### 解题思路
必须写一个思路，搞了一上午。
排序+递增
例如：
[3, 2, 1, 2, 1, 7]
排序后
[1, 1, 2, 2, 3, 7]
最终列表
[1, 2, 3, 4, 5, 7]
max_value记录最终列表的最大值，一定是最右边。
那么每次新来的值，如果小于max_value，一定会变成max_value + 1，新增次数max_value + 1 - A[i]
否则的话直接就是新的最大值，没有新增次数。


### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        if not A:
            return 0
        A.sort()
        max_value = A[0]
        lens = len(A)
        dp = [0] * lens
        for i in range(1, lens):
            if A[i] > max_value:
                dp[i] = dp[i-1]
                max_value = A[i]
            else:
                dp[i] = dp[i-1] + max_value + 1 - A[i]
                max_value = max_value + 1
        return dp[-1]
```