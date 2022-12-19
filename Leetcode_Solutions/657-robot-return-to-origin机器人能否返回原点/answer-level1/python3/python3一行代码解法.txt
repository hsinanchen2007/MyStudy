
```python []
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        return(True if moves.count('R')==moves.count('L') and moves.count('U') ==moves.count('D') else False)
```


