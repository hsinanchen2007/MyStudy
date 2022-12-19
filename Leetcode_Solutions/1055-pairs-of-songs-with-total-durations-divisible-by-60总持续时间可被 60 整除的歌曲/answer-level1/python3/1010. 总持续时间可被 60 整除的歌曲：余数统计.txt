对取余后的时间进行统计，统计过程中将余数的补数数量累加进`ans`。

```python []
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        ans, d = 0, collections.defaultdict(int)
        for i in time:
            ans += d[- i % 60]
            d[i % 60] += 1
        return ans
```