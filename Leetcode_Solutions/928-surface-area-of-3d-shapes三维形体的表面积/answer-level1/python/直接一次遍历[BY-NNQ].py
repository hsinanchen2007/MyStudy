### 解题思路
> 先找特征，独立高度为N的计算公式为 ```AREA(N) = (N-1)*4 + 6``` , 然后遍历减去相交被覆盖的部分；
- 1. 先累加遇到的每一个高度N对应的面积；
- 2. 针对从第二列开始，每增加一个表面，减去 2*MIN(当前列高度,左边列的高度) ;
- 3. 针对从第二行开始，每多一行时，同时减去 2*MIN(当前行高度,上一行的高度) ；

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        def sum_of_n_cube(n):
            if n <= 0:
                return 0
            return (n - 1) * 4 + 6

        total = 0
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                total += sum_of_n_cube(grid[row][col])
                if col > 0:
                    total -= 2 * min(grid[row][col - 1], grid[row][col])
                if row > 0:
                    total -= 2 * min(grid[row][col], grid[row - 1][col])
        return total
```

### 运行情况
```
执行用时 :104 ms, 在所有 Python3 提交中击败了72.03%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了5.77%的用户
```