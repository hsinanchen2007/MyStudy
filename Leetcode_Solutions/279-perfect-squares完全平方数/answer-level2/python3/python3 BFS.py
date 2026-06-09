### 解题思路
BFS就是好使啊！！！！

### 代码

```python3
class Solution:
    def numSquares(self, n: int) -> int:
        #学习一下别人的代码
        #BFS
        deq = collections.deque([n])
        visited = set()
        step = 0
        while True:
            step += 1
            for _ in range(len(deq)):
                temp = deq.pop()
                for j in range(1,int(temp**.5) + 1):
                    x = temp - j**2
                    if x == 0:
                        return step
                    if x not in visited:
                        deq.appendleft(x)
                        visited.add(x)
```