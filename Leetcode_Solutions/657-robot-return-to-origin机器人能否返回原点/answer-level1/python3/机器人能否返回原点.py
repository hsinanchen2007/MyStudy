### 第一种思路 遍历一遍字符串 
### 代码
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        x = 0
        y = 0
        for i in moves:
            if i == 'U':y+=1
            elif i == 'D':y-=1
            elif i == 'L':x-=1
            elif i == 'R':x+=1
        if x== 0 and y == 0:return True
        else:return False
###第二种思路 要使j机器人返回原点，则有上就有下，u'zuo'jiu'you'you
### 代码

```python3
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        return moves.count('U') == moves.count('D') and moves.count('L') == moves.count('R')
```