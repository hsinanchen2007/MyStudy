### 解题思路
亦可以认为是 动态规划 方法
### 代码

```python3
class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        if not rooms:
            return []
        empty = 2**31-1
        w, h = len(rooms), len(rooms[0])
        dp = rooms[:]
        cur_room = []
        # 初始化状态，先找到所有距离为1的room
        dist=1
        for i in range(len(rooms)):
            for j in range(len(rooms[0])):
                if rooms[i][j]==empty:
                    if (i+1 < w and 0 == rooms[i+1][j]) or (i>0 and 0 == rooms[i-1][j]) or (j+1<h and 0 == rooms[i][j+1]) or (j>0 and 0 == rooms[i][j-1]):
                        cur_room.append((i,j))
                        dp[i][j]=dist
        # 再根据距离 广度遍历
        while cur_room:
            dist+=1
            tmp=[]
            for (i,j) in cur_room:
                if i+1<w and rooms[i+1][j]==empty:
                    dp[i+1][j]=dist
                    tmp.append((i+1,j))
                if j+1<h and rooms[i][j+1]==empty:
                    dp[i][j+1]=dist
                    tmp.append((i,j+1))
                if i>0 and rooms[i-1][j]==empty:
                    dp[i-1][j]=dist
                    tmp.append((i-1,j))
                if j>0 and rooms[i][j-1]==empty:
                    dp[i][j-1]=dist
                    tmp.append((i,j-1))
            cur_room=tmp
        return dp

```
亦可以认为是 动态规划 方法
