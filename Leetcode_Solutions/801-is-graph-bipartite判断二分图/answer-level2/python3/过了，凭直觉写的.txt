### 解题思路
dfs递归形式，用了reduce，不然我还真不知道该怎么写，怎么把return衔接起来？求大佬指点，怎么写没有reduce的递归？
### 代码

```python3
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        from functools import reduce
        color=[0]*len(graph)
        def dfs(i,v):
            if color[i]==0:
                color[i]=v
                if not graph[i]:
                    return True
                return reduce(lambda x,y:x and y,[dfs(j,-v) for j in graph[i]])
            elif color[i]==(-v):
                return False
            else:
                return True
        res=True
        for i in range(len(graph)):
            if color[i]==0:
                res=res and dfs(i,1)
        return res
```