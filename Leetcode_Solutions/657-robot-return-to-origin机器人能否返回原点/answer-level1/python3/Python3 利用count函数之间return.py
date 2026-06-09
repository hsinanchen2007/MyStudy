

### 代码

```python3
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        return moves.count('R')-moves.count('L')==0 and moves.count('U')-moves.count('D')==0
```