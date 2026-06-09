```
class Solution(object):
    def maxDistToClosest(self, seats):
        length = len(seats)
        turn = []
        # 把有人坐的座位下标提出来
        for i in range(length):
            if seats[i] == 1:
                turn.append(i)
        # 考虑最左最右是零的情况
        ans = max(turn[0], length-turn[-1]-1)
        # 离他最近的人的最大距离即相邻有人坐的座位之间距离的一半
        for i in range(0, len(turn)-1):
            if (turn[i+1] - turn[i])/2 > ans:
                ans = (turn[i+1] - turn[i]) / 2
        return ans
```
