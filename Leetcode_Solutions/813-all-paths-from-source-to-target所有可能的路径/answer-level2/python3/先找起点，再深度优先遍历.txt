由于题目为寻找有向无环图中遍历所有节点的路径，所以有如下两个结论：

1. 起点必然不是其他节点的下一节点
2. 如果存在一条遍历所有节点的路径，那么非起点节点必然是其他节点的下一节点。

由此可以知道起点不在graph二维数组中出现。因此只需要遍历一遍graph中的所有节点，找到起点后，再使用深度优先遍历即可。

```python
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        # 寻找起点
        n = len(graph)
        hset = set(range(n))
        for i in range(n):
            if i not in hset:
                continue
            for item in graph[i]:
                if item in hset:
                    hset.remove(item)
        start = list(hset)[0]

        # 深度优先遍历
        ans = []
        def dfs(path, i):
            path.append(i)
            if not len(graph[i]):
                ans.append(path)
            else:
                for item in graph[i]:
                    dfs(path.copy(), item)
        dfs([], start)

        return ans
```
