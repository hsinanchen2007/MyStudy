二分思想进行尾部搜索
```python []
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix)==0:  return False
        ans = False
        for x in matrix:
            if len(x) == 0:  break
            if target <= x[-1]:
                for y in x:
                    if target == y: ans = True
        return ans
```

