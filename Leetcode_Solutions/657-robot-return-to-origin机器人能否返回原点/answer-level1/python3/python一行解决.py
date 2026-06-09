只用考虑向上和向下，向左和向右出现的次数是否一样即可 一行代码就能够解决


```
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        return moves.count("L") == moves.count("R") and moves.count("U") == moves.count("D")
```
