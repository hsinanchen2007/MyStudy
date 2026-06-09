### 解题思路
首先建立一个list储存每一扇门能否打开。从第0扇门开始做DFS，注意开过的门不要重新进入，不然会造成循环，出不来while loop。最后如果有门打不开，就返回false，如果所有门都能打开，就返回true。

### 代码

```python
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        can_open = [False for _ in range(len(rooms))]
        s = [0]
        while s:
            door = s.pop()
            if not can_open[door]:
                can_open[door] = True
                for key in rooms[door]:
                    if not can_open[key]:
                        s.append(key)
        return all(can_open)
```