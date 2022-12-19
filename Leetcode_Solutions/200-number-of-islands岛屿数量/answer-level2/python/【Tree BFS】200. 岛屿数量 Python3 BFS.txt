### 解题思路
- 相似题型
- BFS
- DFS
- 代码
- 复杂度

### 相似题型
- [102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-xi-lie-4er-cha-shu-de-ceng-ci-bian-li-p/)
- [107. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/solution/er-cha-shu-xi-lie-107-er-cha-shu-de-ceng-ci-bian-l/)
- [103. 二叉树的锯齿形层次遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/er-cha-shu-xi-lie-103-er-cha-shu-de-ju-chi-xing-ce/)
- [637. 二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/solution/er-cha-shu-xi-lie-637-er-cha-shu-de-ceng-ping-jun-/)
- [111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/er-cha-shu-xi-lie-111-er-cha-shu-de-zui-xiao-shen-/)
- [116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/er-cha-shu-xi-lie-116-tian-chong-mei-ge-jie-dian-d/)
- [117. 填充每个节点的下一个右侧节点指针 II](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/solution/er-cha-shu-xi-lie-117-tian-chong-mei-ge-jie-dian-d/)
- [199. 二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/tree-bfs-199-er-cha-shu-de-you-shi-tu-python3-bfs-/)
- [863. 二叉树中所有距离为 K 的结点](https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/solution/tree-bfs-863-er-cha-shu-zhong-suo-you-ju-chi-wei-k/)




### BFS
指路：[102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-xi-lie-4er-cha-shu-de-ceng-ci-bian-li-p/) 的题解

**重点**：我们已知：`树即为directed graph`，层次遍历就可以用`Breadth Search First`完成，那么同样，对于`二维矩阵`，我们之间就可以认为是`undirected graph`，我们仍然可以用`BFS`来完成

占坑

### DFS
递归是一个分支走到底，这是**DFS**!!!!

**区别**：我们需要用一个`self.check`二维矩阵来保存每个元素的是否处理过的结果，因为我们见过的判断过的元素，我们下一次就不会再次处理了，于是对于二维矩阵中的每个元素，我们都要去遍历一遍，如果`self.check[i][j] == 0 and grid[i][j] == '1'`，即为我们没见过这个元素，而且它还是土地，那么我们就要从它的四周去广度搜索其他可达的土地以凑成一个岛屿，而这一次的开始就代表我们一定能找到一个岛屿，那么`count+=1`，而且我们`DFS`一次`count`只加`1`，说明我们是找到全部的可达土地，才算作一个岛屿

在`DFS`中我们要考虑边界情况，即为：`如果i和j出界了，我们就不再DFS，或者已经见过这个土地(self.check[i][j]==1)，或者这里不是土地(grid[i][j]=='0')，我们也不再DFS`，对于其余情况，我们用`DFS`去找到所有可达土地并更新`self.check`


### 代码

```python3
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or len(grid) < 1:
            return 0
        
        count = 0
        
        rows = len(grid)
        cols = len(grid[0])
        self.check = [[0 for j in range(cols)] for i in range(rows)]
        
        for i in range(rows):
            for j in range(cols):
                if self.check[i][j] == 0 and grid[i][j] == '1':
                    '''
                    对于每一个新的满足条件的遍历起点
                    我们总能找到以它为起点的可达土地
                    '''
                    count += 1
                    self.dfs(grid, rows, cols, i, j)
                    
        return count
    
    def dfs(self, grid, rows, cols, i, j):
        '''base case：越界不再遍历'''
        if i < 0 or i > rows-1 or j < 0 or j > cols-1 or self.check[i][j] == 1 or grid[i][j] == '0':
            return 
        self.check[i][j] = 1

        '''DFS：二维矩阵的上下左右'''
        self.dfs(grid, rows, cols, i-1, j)
        self.dfs(grid, rows, cols, i+1, j)
        self.dfs(grid, rows, cols, i, j-1)
        self.dfs(grid, rows, cols, i, j+1)
```

### 复杂度
- 时间复杂度：O(m*n)
  `m`和`n`分别是二位矩阵的行数和列数
- 空间复杂度：
  最坏情况下为 `O(m*n)`
  此时整个网格均为陆地，深度优先搜索的深度达到 `m*n`


### 2020/4/8
