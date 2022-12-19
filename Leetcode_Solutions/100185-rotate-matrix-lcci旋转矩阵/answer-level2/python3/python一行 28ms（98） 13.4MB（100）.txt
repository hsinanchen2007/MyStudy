```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        matrix[:]=[*map(list, zip(*matrix[::-1]))][:]
```