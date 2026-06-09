代码不是很简洁，凑合用，效率还可以把，一次遍历。


## python3
```
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        degree = [0]*n #节点的度
        result = set([x for x in range(n)])  #待选节点，一开始时全部节点，然后将叶子节点逐层删掉
        if(not n > 2):
            return list(result)
        graph = [[] for x in range(n)]  #构建地图和节点的度
        for node1,node2 in edges:
            graph[node1].append(node2)
            graph[node2].append(node1)
            degree[node1] += 1
            degree[node2] += 1
        queue = []
        for cur in range(n): #初始入队，将叶子节点（节点度为1的节点）入队
            if (degree[cur] == 1):
                queue.append(cur)
                result.remove(cur) #入队说明该节点不可能成为根节点了。
        while len(result) > 2:
            length = len(queue) #获取队列的个数，主要是为了一层一层的遍历
            for _ in range(length):
                cur = queue.pop(0)
                for next in graph[cur]:
                    degree[next] -= 1
                    if(degree[next] == 1):
                        queue.append(next)
                        result.remove(next)
        return list(result)
```