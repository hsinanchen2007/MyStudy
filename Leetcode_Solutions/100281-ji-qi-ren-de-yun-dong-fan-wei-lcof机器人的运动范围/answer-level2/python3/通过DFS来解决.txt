### 解题思路
可以通过DFS和BFS来实现
1. `深搜+剪枝 向下和向右来进行递归，并且设置visited来存储已经访问过的元素，防止重复访问`
2. `广搜用队列`
### 代码

```python
class Solution(object):
    def movingCount(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        #通过DFS来解决
        visited = set()
        def dfs(i,j,si,sj):
            if not 0 <= i < m or not 0 <= j < n or k < si + sj or (i, j) in visited:
                return 0
            visited.add((i, j))
            return 1 + dfs(i + 1, j, si + 1 if (i + 1) % 10 else si - 8,sj) + dfs(i, j + 1, si, sj + 1 if (j + 1) % 10 else sj - 8)
        # visited = set()
        return dfs(0, 0, 0, 0)
        
```