### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        from collections import defaultdict
        memo = [defaultdict(int) for _ in A]
        res = 0
        for i in range(len(A)):
            for j in range(i):
                # 记录当前i到j之间的的间隔
                memo[i][A[i]-A[j]] += 1
                # 如果同样的间隔发生在dp[j]处，那么肯定就是连续同间隔，加到当前的dp[i]，并且加到总结果上
                if A[i]-A[j] in memo[j]:
                    memo[i][A[i]-A[j]] += memo[j][A[i]-A[j]]
                    res += memo[j][A[i]-A[j]]
        return res
```