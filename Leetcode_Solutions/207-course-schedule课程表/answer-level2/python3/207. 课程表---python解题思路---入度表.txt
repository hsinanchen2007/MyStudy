说实话，不会做图的题目，现在学习一下

**[有向无环图](https://baike.baidu.com/item/有向无环图/10972513)**

## 方法1：入度表（广度优先遍历）

首先我们先了解一下什么是有向图的拓扑排序： 由某个集合上的一个[偏序](https://baike.baidu.com/item/偏序/2439087)得到该集合上的一个[全序](https://baike.baidu.com/item/全序/10577699)，这个操作称之为拓扑排序。

用自己的话来说就是从图的开始结点，一直到图的最后结点的顺序集合（这个顺序不固定）

直接拿大神 [Krahets](https://leetcode-cn.com/u/jyd/) 的代码来解释一下

```python
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
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
            # 说明已经学了一本基础课了
            numCourses -= 1
            for cur in adjacency[pre]:
                # 由于之前额基础课已经一个了，所以需要把基础课之和-1
                indegrees[cur] -= 1
                if not indegrees[cur]: queue.append(cur)
        return not numCourses
```

运行结果（官方代码）

```
执行用时 :52 ms, 在所有 Python3 提交中击败了81.02% 的用户
内存消耗 :14.3 MB, 在所有 Python3 提交中击败了45.41%的用户

执行用时 :80 ms, 在所有 Python3 提交中击败了62.91% 的用户
内存消耗 :14.4 MB, 在所有 Python3 提交中击败了45.41%的用户

执行用时 :64 ms, 在所有 Python3 提交中击败了71.18% 的用户
内存消耗 :14.3 MB, 在所有 Python3 提交中击败了45.41%的用户
```

这道题给我了一个启发，其实图并没有那么可怕，图的每个结点可以用列表的形式来保存相关的信息。这道题的思路就是先从那些基础的结点开始，依次往更深层的树进行遍历

欢迎来github上看更多题目的解答[力扣解题思路](https://github.com/WRAllen/LeetCode)

  