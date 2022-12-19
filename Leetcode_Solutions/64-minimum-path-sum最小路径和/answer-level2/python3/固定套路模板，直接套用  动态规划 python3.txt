# 题解
**固定的套路**
62.不同路径[CSDN](https://blog.csdn.net/zhushaojiecumt/article/details/102938160)或[LeetCode](https://leetcode-cn.com/problems/unique-paths/solution/dong-tai-gui-hua-kong-jian-you-hua-python3-by-zhu_/)
63.不同路径II[CSDN](https://blog.csdn.net/zhushaojiecumt/article/details/102941362)或[LeetCode](https://leetcode-cn.com/problems/unique-paths-ii/solution/dong-tai-gui-hua-zhuan-huan-cheng-62ti-python3-by-/)

只需改变边界上的和，剩下继续使用动态规划即可。

## 动态规划
 1. 特判:若$grid$为空，返回$0$
 2. 初始化数组行数$m$和列数$n$。
 3. 初始化第一行的边界路径和，遍历区间$[1,n)$：当前位置的最小路径和等于本身加上上一位置最小路径和，即$grid[0][i]+=grid[0][i-1]$。
 4. 初始化第一列的边界路径和，遍历区间$[1,m)$：当前位置的最小路径和等于本身加上上一位置最小路径和，即$grid[j][0]+=grid[j-1][0]$。
 5. 和之前一样，遍历每一行，遍历区间$[1,m)$：
 	* 遍历每一列，遍历区间$[1,n)$：
 		+ 网格$(x,y)$处的路径和等于网格$(x-1,y)$和网格$(x,y-1)$处的路径和的较小值加上本身，即 $grid[x][y]+=min(grid[x-1][y],grid[x][y-1])$。
 6. 返回右下角的最小路径和，$grid[-1][-1]$。

### 复杂度分析
 - 时间复杂度：$O(M*N)$
 - 空间复杂度：$O(M*N)$，借助$dp$数组保存结果

### Python

```python
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if(not grid):
            return 0
        m=len(grid)
        n=len(grid[0])
        for i in range(1,n):
            grid[0][i]+=grid[0][i-1]
        for j in range(1,m):
            grid[j][0]+=grid[j-1][0]
        for x in range(1,m):
            for y in range(1,n):
                grid[x][y]+=min(grid[x-1][y],grid[x][y-1])
        return grid[-1][-1]
```