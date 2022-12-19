```python
class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort()
        suffix = [0] * len(satisfaction)
        for idx in range(len(satisfaction) - 1, -1, -1):
            if idx == len(satisfaction) - 1:
                suffix[idx] = satisfaction[idx]
            else:
                suffix[idx] = satisfaction[idx] + suffix[idx + 1]
        res = 0
        for i in range(len(satisfaction)):
            res += (i + 1) * satisfaction[i]
        ans = res
        for tmp in suffix:
            res -= tmp
            ans = max(ans, res)
        return ans
```