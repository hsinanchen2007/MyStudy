### 解题思路
BFS常规思路

### 代码

```python3
from collections import deque
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = set()
        # 第0间房在任何情况下都能进
        visited.add(0)
        q = deque()
        # 将第0间房种钥匙列表加入队列
        q.append(rooms[0])
        while q:
            keys = q.popleft()
            for key in keys:
                if key not in visited:
                    q.append(rooms[key])
                    visited.add(key)
        return len(visited) == len(rooms)

```