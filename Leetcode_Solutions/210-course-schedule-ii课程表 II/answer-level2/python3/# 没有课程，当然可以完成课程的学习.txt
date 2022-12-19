### 解题思路
2种方法
方法1:
构建逆邻接表，实现深度优先遍历。
检测这个有向图中有没有环，只要存在环，课程就不能完成。
注意：这个深度优先遍历得通过逆邻接表实现，
当访问一个结点的时候，应该递归访问它的前驱结点，直至前驱结点没有前驱结点为止。
```
class Solution(object):

    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int 课程门数
        :type prerequisites: List[List[int]] 课程与课程之间的关系
        :rtype: bool
        """
        # 课程的长度
        clen = len(prerequisites)
        if clen == 0:
            # 没有课程，当然可以完成课程的学习
            return [i for i in range(numCourses)]

        # 逆邻接表
        inverse_adj = [set() for _ in range(numCourses)]
        # 想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
        # 1 -> 0，这里要注意：不要弄反了
        for second, first in prerequisites:
            inverse_adj[second].add(first)

        visited = [0 for _ in range(numCourses)]
        # print("in_degrees", in_degrees)
        # 首先遍历一遍，把所有入度为 0 的结点加入队列

        res = []
        for i in range(numCourses):
            if self.__dfs(i,inverse_adj, visited, res):
                return []
        return res

    def __dfs(self, vertex, inverse_adj, visited, res):
        """
        注意：这个递归方法的返回值是返回是否有环
        :param vertex: 结点的索引
        :param inverse_adj: 逆邻接表，记录的是当前结点的前驱结点的集合
        :param visited: 记录了结点是否被访问过，2 表示当前正在 DFS 这个结点
        :return: 是否有环
        """
        # 2 表示这个结点正在访问
        if visited[vertex] == 2:
            # DFS 的时候如果遇到一样的结点，就表示图中有环，课程任务便不能完成
            return True
        if visited[vertex] == 1:
            return False
        # 表示正在访问这个结点
        visited[vertex] = 2
        # 递归访问前驱结点
        for precursor in inverse_adj[vertex]:
            # 如果没有环，就返回 False，
            # 执行以后，逆拓扑序列就存在 res 中
            if self.__dfs(precursor, inverse_adj, visited, res):
                return True

        # 能走到这里，说明所有的前驱结点都访问完了，所以可以输出了
        # 并且将这个结点状态置为 1
        visited[vertex] = 1

        # 先把 vertex 这个结点的所有前驱结点都输出之后，再输出自己
        res.append(vertex)
        # 最后不要忘记返回 False 表示无环
        return False
```
### 代码
方法2:
拓扑排序。构建的邻接表就是我们通常认识的邻接表，每一个结点存放的是后继结点的集合。
前提条件
    clen = len(prerequisites)
#         if clen == 0:
#             # 没有课程，当然可以完成课程的学习
#             return [i for i in range(numCourses)]   
   
 for item in prerequisites:
#             # first->list(second)
#             if item[1] in dic:
#                 dic[item[1]].append(item[0])
#             else:
#                 dic[item[1]] = [item[0]]

#             indegree[item[0]] += 1
```
        
最后检查结果集中的顶点个数是否和课程数相同即可。
```python3
# class Solution:
#     def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        
#         clen = len(prerequisites)
#         if clen == 0:
#             # 没有课程，当然可以完成课程的学习
#             return [i for i in range(numCourses)]        

#         indegree = [0]*numCourses
#         dic = collections.defaultdict(list)
#         res = []

#         for item in prerequisites:
#             # first->list(second)
#             if item[1] in dic:
#                 dic[item[1]].append(item[0])
#             else:
#                 dic[item[1]] = [item[0]]

#             indegree[item[0]] += 1
        
#         queue = []
#         # visited = [False] * numCourses
#         total_cls = 0
#         for i in indegree:
#             if i == 0:
#                 queue.append(i)
        
#         while queue:

#             cur = queue.pop(0)
#             total_cls += 1
#             res.append(cur)
#             sub_courses = dic[cur]

#             if not sub_courses:
#                 continue

#             for i in sub_courses:
#                 indegree[i] -= 1
#                 if indegree[i] == 0:
#                     queue.append(i)
#                     # visited[i] = True
#         print(res)
#         return res if total_cls == numCourses else []
        
                    
                


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        
        # 课程的长度
        N = len(prerequisites)
        if N == 0:
            # 没有课程，当然可以完成课程的学习
            return [i for i in range(numCourses)]
        # 入度数组，一开始全部为 0
        in_degrees = [0 for _ in range(numCourses)]
        # 邻接表
        adj = [set() for _ in range(numCourses)]
        # 想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
        # 1 -> 0，这里要注意：不要弄反了
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
        count = 0
        while queue:
            cur = queue.pop(0)
            res.append(cur)
            count = count + 1 

            for suc in adj[cur]:
                in_degrees[suc] -= 1
                if in_degrees[suc] == 0:
                    queue.append(suc)
        # if len(res) != numCourses:
        #     return []
        # return res
        return res if count == numCourses else []







```