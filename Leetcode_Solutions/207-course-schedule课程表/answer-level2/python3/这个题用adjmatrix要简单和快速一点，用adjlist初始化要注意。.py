### 解题思路
此处撰写解题思路

### 代码

```python3
# class Solution:
#     def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
#         adlist = collections.defaultdict(list)

#         for i in range(numCourses):
#             adlist[i].append(None)

#         for i in prerequisites:
#             adlist[i[0]].append(i[1])
        
#         print(adlist)
        
#         visited = {}
#         counter = {}
#         queue = []
#         # print(adlist)
#         for k,v in adlist.items():
#             print(k,v)
#             if not v[-1]:
#                 queue.append(k)
        
#         print("queue",queue)     
#         for k,v in adlist.items():
#             if k in counter:
#                 counter[k] += len(v)
#             else:
#                 counter[k] = len(v)
#         count = 0 
#         print(counter)
#         print(queue)
#         while queue:
#             node = queue.pop(0)
#             count+=1
#             # this is the process
#             for k,v in adlist.items():
#                 print(v)
#                 if node in v:
#                     v.remove(node)
#                     counter[k]-=1
#             # this is how we add node to our queue
#             for nb in adlist[node]:
#                 print(nb)
#                 if nb is None:
#                     continue
#                 if counter[nb] == 0 and not visited[nb]:
#                     queue.append(nb)
#                     visited[nb] = True
#                 else:
#                     return False

#         return counter == numCourses


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegrees = [0 for _ in range(numCourses)]
        adjacency = [[] for _ in range(numCourses)]
        queue = []
        # Get the indegree and adjacency of every course.
        for cur, pre in prerequisites:
            indegrees[cur] += 1
            adjacency[pre].append(cur)
        # Get all the courses with the indegree of 0.
        for i in range(len(indegrees)):
            if not indegrees[i]: queue.append(i)
        # BFS TopSort.
        while queue:
            pre = queue.pop(0)
            numCourses -= 1
            for cur in adjacency[pre]:
                indegrees[cur] -= 1
                if not indegrees[cur]: queue.append(cur)
        return not numCourses

```


        # 入度数组，一开始全部为 0
        in_degrees = [0 for _ in range(numCourses)]
        # 邻接表
        adj = [set() for _ in range(numCourses)]

        # 想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
        # [0,1] 表示 1 在先，0 在后
        # 注意：邻接表存放的是后继 successor 结点的集合
        for second, first in prerequisites:
            in_degrees[second] += 1
            adj[first].add(second)

        # print("in_degrees", in_degrees)
        # 首先遍历一遍，把所有入度为 0 的结点加入队列
        res = []
        queue = []
        for i in range(numCourses):
            if in_degrees[i] == 0:
                queue.append(i)
        counter = 0
        while queue:
            top = queue.pop(0)
            counter += 1

            for successor in adj[top]:
                in_degrees[successor] -= 1
                if in_degrees[successor] == 0:
                    queue.append(successor)

        return counter == numCourses