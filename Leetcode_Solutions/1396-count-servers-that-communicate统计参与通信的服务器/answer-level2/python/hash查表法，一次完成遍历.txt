### 解题思路

主程序
1、依次遍历每一个网格
    如果网格是空节点，跳过
    该节点的行列处于hashtable中，或者该节点右或下方还有服务器节点（说明该节点可以通信）
        服务器计数加1，更新hashtable
2、辅助查找节点
    向右遍历，找到服务器节点，返回true
    向下遍历，找到服务器节点，返回true
    返回false


### 代码

```python
class Solution(object):
    def searchRightDown(self, grid, i, j):
        for k in range(j+1, len(grid[0])):
            if grid[i][k]==1:return True
        for k in range(i+1, len(grid)):
            if grid[k][j]==1:return True
        return False

    def countServers(self, grid):
        if not grid:return 0
        m,n,cnt = len(grid), len(grid[0]), 0
        # hashtable，保存联通节点的行列
        tabLine = [False for _ in range(m)]
        tabCol = [False for _ in range(n)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    continue
                if tabLine[i] or tabCol[j] or self.searchRightDown(grid, i, j):
                    cnt = cnt + 1
                    tabLine[i] = tabCol[j] = True
        return cnt

```