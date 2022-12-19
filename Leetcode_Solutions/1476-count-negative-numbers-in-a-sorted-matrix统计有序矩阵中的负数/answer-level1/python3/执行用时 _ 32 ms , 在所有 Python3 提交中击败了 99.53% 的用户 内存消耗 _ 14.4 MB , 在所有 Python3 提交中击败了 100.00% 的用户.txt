
```
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        n = len(grid)
        ans = 0

        for i in grid:
            left, right = 0, len(i)-1
            while left < right:
                mid = (left + right)//2
                if i[mid] >= 0:
                    left = mid + 1
                else:
                    right = mid
            if i[left] < 0:
                ans += len(i) - left

        return ans```
```
代码块
```
