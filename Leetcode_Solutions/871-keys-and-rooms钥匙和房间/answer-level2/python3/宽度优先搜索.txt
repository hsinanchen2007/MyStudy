```
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        """
           看到题目表示是否能够遍历, 很显然就是一个搜索问题了
        """
        if not rooms:
            return True

        stack = [x for x in rooms[0]]
        # 首先第0个房间中所有的key指向的房间我们都能访问到
        visted = set(stack)
        # 房间0也已经访问过
        visted.add(0)
        while stack:
            curr_room_i = stack.pop(0)
            
            tmp_link_ = rooms[curr_room_i]

            if tmp_link_:
                for key in tmp_link_:
                    if key not in visted:
                        stack.append(key)
                        visted.add(key)
        
        return True if len(visted) == len(rooms) else False
```
