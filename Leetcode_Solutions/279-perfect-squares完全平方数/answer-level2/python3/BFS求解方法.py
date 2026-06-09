### 解题思路
bfs

### 代码

```python3
from collections import deque
class Solution:
    def numSquares(self, n: int) -> int:
        seq=0
        queue=deque([n])
        include=set()#添加已经计算过的元素,如果计算过,就不会再次计算,避免增加时间复杂度
        while queue:
            lens=len(queue)#队列的长度
            for i in range(lens):
                ret=queue.popleft()
                a=int(ret**0.5) #求出ret可以减的所有 完全平方数a*a
                while a>0:
                    mid=ret-a*a #mid为每次计算过程中的中间值
                    if mid==0:
                        return seq+1
                    if mid not in include:
                        include.add(mid)
                        queue.append(mid)
                    a-=1
            seq+=1
```