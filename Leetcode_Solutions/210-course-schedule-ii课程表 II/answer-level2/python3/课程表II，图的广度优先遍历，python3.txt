### 解题思路
参考[https://leetcode-cn.com/problems/course-schedule/solution/ke-cheng-biao-yan-du-you-xian-bian-li-python3-by-c/](207.课程表)
### 代码

```python3
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        son = {i:[] for i in range(numCourses)}
        indegree = [0 for _ in range(numCourses)]
        for m, n in prerequisites:
            son[n].append(m)
            indegree[m] += 1
        
        queue = []
        for i in range(len(indegree)):
            if indegree[i] == 0:
                numCourses -= 1
                queue.append(i)
        k = 0
        while k < len(queue):
            cur = queue[k]
            for i in range(len(son[cur])):
                indegree[son[cur][i]] -= 1
                if indegree[son[cur][i]] == 0:
                    queue.append(son[cur][i])
                    numCourses -= 1
            k += 1
        if not numCourses: return queue
        else: return []
```