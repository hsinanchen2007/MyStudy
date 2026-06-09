### 解题思路
Kahn算法：
1. 计算图中所有点的入度，把入度为0的点加入栈；
2. 如果栈非空：
    a. 取出栈顶顶点node，输出该顶点值并删除顶点node；
    b. 从图中删除所有以node为起始点的边，如果删除的边的另一个顶点入度为0，则把它入栈；
3. 如果图中还存在顶点，则表示图中存在环；否则输出的顶点就是一个拓扑排序序列；


### 代码

```python3
class Solution:
    """
    先决条件相当于有向边的集合，本题的核心是判断该图中是否存在环，有则返回False，否则True；
    注意：这里不一定是连通图；
    """
    def adjacentMatrix(self, n, prerequisites):
        """
        用邻接表结构存储图，其中adjacent_matrix[i][j]表示节点j->i；
        """
        adjacent_matrix = [[0 for _ in range(n)] for _ in range(n)]
        for node1, node2 in prerequisites:
            adjacent_matrix[node1][node2] = 1
        return adjacent_matrix

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        """
        用kahn算法判断是否存在环
        """
        if numCourses == 0:
            return True
        adjacent_matrix = self.adjacentMatrix(numCourses, prerequisites)
        # in_degrees存储每个节点的入度
        in_degrees = [sum(adjacent_matrix[i]) for i in range(numCourses)]

        # stack存储入度为0的节点
        stack = []
        for i in range(numCourses):
            if in_degrees[i] == 0:
                stack.append(i)
        
        # count表示节点数
        count = numCourses
        while stack:
            # 弹出stack的顶点
            node = stack.pop()
            # 将该顶点从图中删除
            count -= 1
            # 并将以node为起始点的边删除，将入度为0的顶点加入stack
            for i in range(numCourses):
                if adjacent_matrix[i][node] == 1:
                    adjacent_matrix[i][node] = 0
                    in_degrees[i] -= 1
                    if in_degrees[i] == 0:
                        stack.append(i)
                
        # count==0表示图中不存在节点，图中无环；否则存在环；
        if count == 0:
            return True
        else:
            return False

```