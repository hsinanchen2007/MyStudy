### 解题思路
* 最开始做的时候，我建立的`visited`数组是二维的，可能智商不在线吧。当然是用一维啦朋友。
* 思路：遍历每个人，如果没访问过，那么用bfs/dfs找寻ta的朋友圈，`res`加一。

### 代码

```python []
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        m = len(M)
        visited = [0] * m 
        res = 0
        queue = []

        for i in range(m):
            if visited[i] == 0:
                # bfs
                queue.append(i)
                visited[i] = 1
                while(len(queue) != 0):
                    i = queue.pop()
                    for j in range(m):
                        if i != j and M[i][j] == 1 and visited[j] == 0:
                            queue.append(j)
                            visited[j] = 1
                res += 1
        return res
```

* 时间复杂度：O(n2)
* 空间复杂度：O(n)