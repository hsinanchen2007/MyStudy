### 解题思路
参考[题解入度表法](https://leetcode-cn.com/problems/course-schedule/solution/course-schedule-tuo-bu-pai-xu-bfsdfsliang-chong-fa/)，在每次弹出入度为0的课程时加进学习列表中，若没有环则返回该学习列表即可；

### 代码

```python3
class Solution:
    """
    kahn实现拓扑排序
    """
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        if not numCourses:
            return []


        # study_flow为学习过程, count记录删除的节点
        study_flow, count = [], 0
        # in_degrees记录每个节点的入度
        in_degrees = [0 for _ in range(numCourses)]
        # adjacent_matrx为邻接矩阵，并计算每个节点的入度
        adjacent_matrix = [[] for _ in range(numCourses)]
        for cur, pre in prerequisites:
            adjacent_matrix[pre].append(cur)
            in_degrees[cur] += 1
        # stack记录入度为0的节点
        stack = []
        for cur in range(numCourses):
            if not in_degrees[cur]:
                stack.append(cur)

        while stack:
            cur = stack.pop()
            study_flow.append(cur)
            count += 1
            for nxt in adjacent_matrix[cur]:
                in_degrees[nxt] -= 1
                if not in_degrees[nxt]:
                    stack.append(nxt)
        
        if count < numCourses:
            return []
        else:
            return study_flow
```