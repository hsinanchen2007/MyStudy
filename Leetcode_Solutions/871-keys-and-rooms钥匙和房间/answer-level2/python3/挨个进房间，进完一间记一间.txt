从第一间房子开始依次，广度优先的规则把所有房子都进一遍，每次进新房都标记一下，如果是老房子就不用再进一遍，最后数数进过的房子有多少间就可以了。
```
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        stack = [rooms[0]]
        res = [False for _ in range(len(rooms))]
        res[0] = True

        while stack:
            curr = stack.pop()
            for i in range(len(curr)):
                if res[curr[i]]:
                    pass
                elif not res[curr[i]]:
                    res[curr[i]] = True
                    stack.append(rooms[curr[i]])
                    
        for r in res:
            if not r:
                return False
        return True
```
