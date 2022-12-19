### 解题思路
三种方法，python实现

### 代码

```python
class Solution(object):
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        # 1.同一朋友圈的ID编号设置为相同
        '''
        n = len(M)
        relation = list(range(n))
        def connect(i, j, relationList):
            t = relationList[j]
            s = relationList[i]
            for i in range(len(relationList)):
                if relationList[i] == t:
                    relationList[i] = s
        for i in range(n):
            for j in range(n):
                if j < i and M[i][j] == 1:
                    connect(j, i, relation)
        return len(set(relation))
        '''
        # 2.深度优先搜索
        '''
        def dfs(M, i, visited):
            visited[i] = 1
            for j in range(len(M)):
                if M[i][j] == 1 and visited[j] == 0:
                    visited[j] = 1
                    dfs(M, j, visited)
        n = len(M)
        visited = [0]*n
        count = 0
        for i in range(n):
            if visited[i] == 0:
                dfs(M, i, visited)
                count += 1
        return count
        '''
        # 3.广度优先搜索
        def bfs(M, q, visited):
            while q:
                i = q.pop(0)
                visited[i] = 1
                for j in range(len(M)):
                    if M[i][j] == 1 and visited[j] == 0:
                        q.append(j)
                        visited[j] == 1
        count = 0
        n = len(M)
        q = []
        visited = [0]*n
        for i in range(n):
            if visited[i] == 0:
                q.append(i)
                bfs(M, q, visited)
                count += 1
        return count


```