```python
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        for item in A:
            item.reverse()
            for i, val in enumerate(item):
                item[i] = abs(val - 1)
        return A
```