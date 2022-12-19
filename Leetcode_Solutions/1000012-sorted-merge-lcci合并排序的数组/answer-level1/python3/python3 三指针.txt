```
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        point1 = len(A) - len(B) - 1
        point2 = len(B) - 1
        point3 = len(A) - 1
        while point3 >= 0:
            if point1 >= 0 and (point2 < 0 or A[point1] >= B[point2]):
                A[point3] = A[point1]
                point1 -= 1
                point3 -= 1
            elif point2 >= 0 and (point1 < 0 or A[point1] < B[point2]):
                A[point3] = B[point2]
                point2 -= 1
                point3 -= 1
```
