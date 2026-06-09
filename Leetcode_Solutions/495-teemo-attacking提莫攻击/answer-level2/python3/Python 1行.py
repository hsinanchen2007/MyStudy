```python
class Solution:
    def findPoisonedDuration(self, t: List[int], d: int) -> int:
        return len(t) and sum(min(t[i] - t[i-1], d) for i in range(1, len(t))) + d
```
- 总时间 = 所有间隔时间的总和，每一次的间隔时间 = min(下次发射时间 - 这次发射时间，duration)