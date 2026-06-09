## 思路：
观察题意可以发现，

只要先把二维网格里所有的元素按顺序提取出来，

把最后`k`个数提取出来，并插入到数组的开头，

再把新的数组按顺序放回到二维网格即可。

## 代码实现：
```Python
class Solution(object):
    def shiftGrid(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        m, n = len(grid), len(grid[0])
        
        size = m * n
        k = k % size  
        l = [grid[i][j] for i in range(m) for j in range(n)]
           
        l = l[-k:] + l[:-k]
        
        for i in range(m):
            for j in range(n):
                grid[i][j] = l[i * n + j]
        return grid
```
## 复杂度分析：
时间复杂度：$O(MN)$
空间复杂度：$O(MN)$