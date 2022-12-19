```python3
class Solution:
    def hanota(self, A: List[int], B: List[int], C: List[int]) -> None:
        """
        Do not return anything, modify C in-place instead.
        """
        n = len(A)
        def moveDisk(fromList, toList):
            temp = fromList.pop()
            toList.append(temp)
        def moveTower(n, A, B, C):
            if n >= 1:
                moveTower(n-1, A, C, B)
                moveDisk(A, C)
                moveTower(n-1, B, A, C)
        moveTower(n, A, B, C)
```
