动态规划

`dp[i]`到以索引`i`为最后一个数差值为`A[i] - A[i - 1]`的等差数列的个数

写法1:

```python
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        from collections import defaultdict
        if len(A) <= 2: return 0
        dp = [defaultdict(lambda :-1) for _ in range(len(A))]
        res = 0

        for i in range(1, len(A)):
            diff = A[i] - A[i - 1]
            dp[i][diff] = dp[i - 1][diff] + 1
            res += dp[i][diff]

        return res
```

写法2:

```python
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        if len(A) <= 2: return 0
        cur = 0
        res = 0

        for i in range(2, len(A)):
            if A[i] - A[i - 1] == A[i - 1] - A[i - 2]:
                cur += 1
                res += cur
            else:
                cur = 0

        return res
```

