![image.png](https://pic.leetcode-cn.com/c1579980b50146cd95373ebef3a449fba8fd9ab803bf9b1f50c90555f786a3f0-image.png)


```
'''
bfs 枚举所有可能到达的位置, 检查其中有没有数值是0的位置
'''


from typing import List
from queue import Queue
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        visited = [0 for _ in range(n)]

        if arr[start] == 0:
            return True

        que = Queue()
        que.put(start)
        visited[start] = 1

        while not que.empty():
            cur = que.get()

            for next in [cur - arr[cur], cur + arr[cur]]:
                if next >= 0 and next < n and visited[next] == 0:
                    visited[next] = 1
                    if arr[next] == 0:
                        return  True

                    que.put(next)

        return False
```
