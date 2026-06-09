### 解题思路
广度优先搜索

### 代码

```
class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        graph = [[0]*(n+1) for _ in range(n+1)]
        for f,to in edges:
            graph[f][to] = 1
            graph[to][f] = 1
        visited = [False] * (n + 1)

        def count(node):#计算连接节点中未访问的个数
            cnt = 0
            for i in range(1,n+1):
                if graph[node][i] == 1 and visited[i] == False:
                    cnt += 1
            return cnt


        queue = []
        queue.append((1,1,0))
        visited[1] = True
        while queue:
            node,probs,steps = queue.pop(0)
            if node == target:
                if steps == t or (steps<t and not count(node)):return probs
                else:
                    return 0
            else:
                probability = 1.0 / count(node) if count(node) else 1
                for i in range(1,n+1):
                    if graph[node][i] == 1 and not visited[i]:
                        visited[i] = True
                        queue.append((i,probs*probability,steps+1))
        return 0 
```

![image.png](https://pic.leetcode-cn.com/97f3c0b6e784daef8be3effecdb7dbeda1cb0c059c218770bebc51851d9ae514-image.png)
