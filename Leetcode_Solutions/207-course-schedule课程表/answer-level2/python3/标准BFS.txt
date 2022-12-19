### 解题思路
标准BFS

### 代码

```python
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # if not prerequisites:
        #     return False
        in_degree, neigbhors = self.get_in_degree(numCourses, prerequisites)
        queue = collections.deque([n for n in neigbhors if in_degree[n] == 0])
        result = []
        while queue:
            n = queue.popleft()
            result.append(n)
            for x in neigbhors[n]:
                in_degree[x] -= 1
                if in_degree[x] == 0:
                    queue.append(x)
        return len(result) == numCourses
                
        
    
    def get_in_degree(self, numCourses, prerequisites):
        result = {n: 0 for n in range(numCourses)}
        neigbhors = {n: [] for n in range(numCourses)}
        for i, j in prerequisites:
            result[j] += 1
            neigbhors[i].append(j)
        return result, neigbhors
```
![image.png](https://pic.leetcode-cn.com/34bef5de8190460b355352b7daa0b5f863c11f20ef48ddc5de0d53b130bdc9b3-image.png)
