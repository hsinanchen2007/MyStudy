### 解题思路
从矩阵的右下角开始逆序查找，当正在查找的元素为非负数时，记录当前下标，从下一轮遍历开始，以此为下界。
复杂度为O(k)，k为矩阵中的负数个数。
执行用时 :220 ms, 在所有 Python3 提交中击败了100.00%的用户
内存消耗 :14.1 MB, 在所有 Python3 提交中击败了100.00%的用户

### 代码

```python3
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0
        m = len(grid)
        n = len(grid[0])
        x, y = -1, -1
        for i in range(m - 1, x, -1):
            for j in range(n - 1, y, -1):
                if grid[i][j] < 0:
                    count += 1
                else:
                    y = j
            if grid[i][0] > 0:
                x = i
        return count
```