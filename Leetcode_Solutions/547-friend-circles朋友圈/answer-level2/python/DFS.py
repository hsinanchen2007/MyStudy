DFS标准形式
```
class Solution(object):
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        cnt,N = 0,len(M)
        fri = set()
        def dfs(n):
            for x in range(N):
                if M[n][x] and x not in fri:
                    fri.add(x)
                    dfs(x)
        for i in range(N):
            if i not in fri:
                cnt += 1
                dfs(i)
        return cnt
```
