![QQ截图20200228200359.jpg](https://pic.leetcode-cn.com/fc4f29c9e63e7aefecdcab95b160a52246c429041e77b34e2b845aacb1db71d2-QQ%E6%88%AA%E5%9B%BE20200228200359.jpg)
```
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indegree = [0 for _ in range(numCourses)]
        adj = [[] for _ in range(numCourses)]
        queue = []
        res = []
        for cur, pre in prerequisites:
            indegree[cur] += 1
            adj[pre].append(cur)
        for i in range(numCourses):
            if indegree[i] == 0:
                queue.append(i)
        while queue:
            pre = queue.pop(0)
            res.append(pre)
            numCourses -= 1
            for cur in adj[pre]:
                indegree[cur] -= 1
                if indegree[cur] == 0:
                    queue.append(cur)
        if numCourses == 0:
            return res
        else:
            return []
```
