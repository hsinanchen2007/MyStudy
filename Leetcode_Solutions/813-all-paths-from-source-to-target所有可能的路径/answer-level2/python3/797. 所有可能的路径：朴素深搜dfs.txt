![image.png](https://pic.leetcode-cn.com/3b1c0af5311e9dfc2217684ee8b38cee643281ac3f50ba2248c4c3f29418e978-image.png)

参数分别是当前节点`i`以及累计路径`p`，遇到终点就输出进`ans`。

```python []
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans, t = [], len(graph) - 1
        def f(i, p):
            if i == t:
                ans.append(p + [i])
            else:
                for j in graph[i]:
                    f(j, p + [i])
        f(0, [])
        return ans
```
