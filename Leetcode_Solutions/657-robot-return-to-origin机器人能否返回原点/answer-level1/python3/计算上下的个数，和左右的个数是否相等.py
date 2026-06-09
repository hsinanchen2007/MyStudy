
### 代码

```python3
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        dp = [0, 0]
        if moves.count("R") == moves.count("L") and moves.count("U") == moves.count("D"):
            return True
        else:
            return False

```