### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        return moves.count('U') == moves.count('D') and moves.count('L') == moves.count('R')

```