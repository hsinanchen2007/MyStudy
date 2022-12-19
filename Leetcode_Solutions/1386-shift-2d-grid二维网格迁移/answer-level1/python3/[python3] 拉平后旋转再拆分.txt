首先将二维矩阵拉平成一维矩阵, 然后将 k 对 长度求余数, 得到最终的旋转元素, 最后再将一维矩阵拆分成二维矩阵;

```python
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        if not (grid and grid[0]):
            return grid
        n, m = len(grid), len(grid[0])
        flatten = sum(grid, [])
        length = len(flatten)
        k = k % length
        if k == 0:
            return grid
        flatten = flatten[-k:] + flatten[:-k]
        for i in range(n):
            grid[i] = flatten[i * m:(i + 1) * m]
        return grid
        
```

![image.png](https://pic.leetcode-cn.com/277776ae159ca6a79429ba619fcfc3e7d86e54458967a8caa9a0f8cb8c774abf-image.png)
