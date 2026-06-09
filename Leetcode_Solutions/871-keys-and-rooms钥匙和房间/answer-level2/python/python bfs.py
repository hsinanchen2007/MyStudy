```python
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        seen = {0}
        q = [0]
        while q:
            cur = q.pop(0)
            for i in set(rooms[cur]):
                if i not in seen:
                    seen.add(i)
                    q.append(i)
        return len(seen) == len(rooms)
```