```python
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for i in range(len(s) - 1, 0, -1): s.insert(i, s.pop(0))
```
- 取出来，插到对应位置