### 解题思路
采用递归来解本题：
1，设置一个记录进入过的房间的集合
2，先进入第一间房间，把该房间序号计入进过的房间
3，获取当前进入房间里面的钥匙，每个钥匙代表一间房，逐个钥匙重复上述步骤
4，递归出口：当前要进入的房间已经进过了
5，最后判断所有进入过的房间和给定房间数是否一致

### 代码

```python3
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        def recursion(num, rooms, entered):
            if num in entered:
                return
            entered.add(num)
            keys = rooms[num]
            if keys:
                for k in keys:
                    recursion(k, rooms, entered)
        entered = set()
        recursion(0, rooms, entered)
        return len(entered) == len(rooms)


```