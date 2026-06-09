### 解题思路
利用二分找到大于0的右边界

### 代码

```python
class Solution(object):
    def countNegatives(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        res = []
        for row in grid:
            n = len(row)
            left, right = 0, n
            while left < right:
                mid = (left + right) // 2
                if row[mid] == 0:
                    left = mid + 1
                elif row[mid] > 0:
                    left = mid + 1
                elif row[mid] < 0:
                    right = mid
            res.append(n - left)
            # print(res)
        return sum(res)
```