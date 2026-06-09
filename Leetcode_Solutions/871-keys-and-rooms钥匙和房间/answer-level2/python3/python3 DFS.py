DFS，访问过的房间用set存储
```
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        self.r = {0}
        self.room(rooms[0], rooms)
        return len(self.r) == len(rooms)    
    
    def room(self, l, rooms):
        for j in l:
            if j not in self.r:
                self.r.add(j)
                self.room(rooms[j], rooms)
```
