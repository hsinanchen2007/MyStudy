### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        u_count = moves.count('U')
        d_count = moves.count('D')
        l_count = moves.count('L')
        r_count = moves.count('R')
        if u_count==d_count and l_count==r_count:
            return True
        else:
            return False
```