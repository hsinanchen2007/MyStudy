两种特殊情况单独讨论，其他直接range()
```python
class Solution:
    def divingBoard(self, shorter: int, longer: int, k: int) -> List[int]:
        if k == 0:
            return []
        elif shorter == longer:
            return [k*shorter]
        return range(shorter*k, longer*k + 1, (longer-shorter))
```
