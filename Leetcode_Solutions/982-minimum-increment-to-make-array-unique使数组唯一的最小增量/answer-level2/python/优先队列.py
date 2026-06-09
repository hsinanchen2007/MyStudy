### 解题思路
优先队列
最小堆

### 代码

```python3
import heapq
class Solution:
    def minIncrementForUnique(self, A) -> int:
        data = A
        heapq.heapify(data)
        garbage = []
        move = 0
        while data:
            tmp =heapq.heappop(data)
            if len(garbage) == 0:
                garbage.append(tmp)
            elif tmp==garbage[-1]:
                garbage.append(tmp+1)
                move += 1
            elif tmp>garbage[-1]:
                garbage.append(tmp)
            elif tmp<garbage[-1]:
                garbage.append(garbage[-1]+1)
                move += (garbage[-1]-tmp)
        return move
```