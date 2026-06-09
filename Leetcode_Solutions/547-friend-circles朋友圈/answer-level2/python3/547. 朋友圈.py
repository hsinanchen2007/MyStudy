### 解题思路
如果能看出这道题是求图的连通子图个数，那么问题就很好解决了。时间复杂度为O(N^2)，空间复杂度为O(N)。

### 代码

```python3
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        if not M or not M[0]:
            return 0
        def dfs(vetex,visited):
            if vetex>=vetex_num or vetex<=-1:
                return
            visited[vetex]=True
            for j in range(vetex_num):
                if not visited[j] and M[vetex][j]==1:
                    dfs(j,visited)
        # 看作找图的连通子图个数
        vetex_num = len(M)
        visited = [False]*vetex_num
        res = 0
        for i in range(vetex_num):
            if not visited[i]:
                dfs(i,visited)
                res+=1
        return res
```