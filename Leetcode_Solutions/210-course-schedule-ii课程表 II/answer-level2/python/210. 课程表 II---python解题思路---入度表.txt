## 方法1：入度表（广度优先搜索）

这题是由[207. 课程表](https://leetcode-cn.com/problems/course-schedule/)这题找过来的，思路一样，多了个路径选择时的保存

```python
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        result = []
        # indegress表示对应课程的基础课程之和
        indegrees = [0 for _ in range(numCourses)]
        # adjacency表示对应课程的相邻关系，就是当前课程是哪些课程的基础
        adjacency = [[] for _ in range(numCourses)]
        queue = deque()
        # 初始化各个课程需要的基础课程之和
        for cur, pre in prerequisites:
            indegrees[cur] += 1
            adjacency[pre].append(cur)
        # 获取其实结点
        for i in range(len(indegrees)):
            if not indegrees[i]: queue.append(i)
        # 开始广度优先搜索
        while queue:
            pre = queue.popleft()
            result.append(pre)
            # 说明已经学了一本基础课了
            numCourses -= 1
            for cur in adjacency[pre]:
                # 由于之前额基础课已经一个了，所以需要把基础课之和-1
                indegrees[cur] -= 1
                if not indegrees[cur]: queue.append(cur)
        return [] if numCourses else result
```

运行结果

```
执行用时 :48 ms, 在所有 Python3 提交中击败了87.36% 的用户
内存消耗 :14.5 MB, 在所有 Python3 提交中击败了34.12%的用户

执行用时 :44 ms, 在所有 Python3 提交中击败了93.24% 的用户
内存消耗 :14.4 MB, 在所有 Python3 提交中击败了34.12%的用户

执行用时 :44 ms, 在所有 Python3 提交中击败了93.24% 的用户
内存消耗 :14.5 MB, 在所有 Python3 提交中击败了34.12%的用户
```

欢迎来github上看更多题目的解答[力扣解题思路](https://github.com/WRAllen/LeetCode)

  