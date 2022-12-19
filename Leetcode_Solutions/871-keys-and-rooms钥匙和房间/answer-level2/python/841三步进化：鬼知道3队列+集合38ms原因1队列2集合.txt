### 方法1队列
执行用时 :148 ms, 在所有 Python3 提交中击败了7.39%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了10.10%的用户

1、手上有的钥匙keys，进去过的房间roomsed 
2、从keys中取出末尾的keys[-1]=visiting
3、visiting 如果不在进去过的房间 roomsed 中的话，访问 visiting ，将 visiting 加入到roomsed。并将 rooms[visiting] 加入到 keys中
4、直到keys为空，roomsed和rooms长度一样就是访问了所有房间

### 代码

```python3
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:      
        keys，roomsed=[0]，[]
        while keys:         
            visiting=keys.pop() 
            if visiting not in roomsed:
                roomsed.append(visiting)
                keys=keys+rooms[visiting]
        return len(roomsed)==len(rooms)
```
### 方法2集合
100 ms	13.8 MB
集合思路和队列思路一致。只是换了实现方法，使用取差集的方式替换循环，提升一点效率：
1、先将rooms[visiting] 加入到keys中：`keys.update(set(rooms[visiting]))`
2、然后将keys和roomsed取差集重新赋值给keys：`keys=keys.difference(roomsed)`

### 代码

```python3
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        keys,roomsed={0},set()
        while keys:
            visiting=keys.pop() 
            roomsed.add(visiting)
            keys.update(set(rooms[visiting]))
            keys=keys.difference(roomsed)
        return len(roomsed)==len(rooms)
```
### 方法3队列+集合
96 ms	13.8 MB
由于学习优秀解法发现将队列和集合混用能达到38ms，实际提交只能达到96ms.优秀解法超高效率原因未知，只有鬼知道。