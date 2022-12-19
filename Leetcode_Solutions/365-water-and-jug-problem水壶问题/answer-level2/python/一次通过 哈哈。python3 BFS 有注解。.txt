### 解题思路
此处撰写解题思路

### 代码

```python3
import collections
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        self.searched = set()
        def append(q, x, y):
            state = x, y
            if state not in self.searched:
                self.searched.add(state)
                q.append(state)
            
        q = collections.deque()
        beginStat = (0, 0)
        q.append(beginStat)
        while q:
            k1, k2 = q.popleft()
            if k1 + k2 == z:
                return True
            # case1
            #fill up first kettle : x
            append(q, x, k2)
            #fill up seconed kettle: y
            append(q, k1, y)
            
            # case2
            #pour away from k1
            append(q, 0, k2)
            #pour away from k2
            append(q, k1, 0)

            # case3    
            #k1 to k2
            available = y - k2
            append(q, max(0, k1-available), min(y, k2+k1))
            #k2 to k1
            available = x - k1
            append(q, min(k1+k2, x), max(0, k2-available))
        return False

            


```