### 解题思路
只需要判断左右次数是否相等，上下次数是否相等即可,两者满足即可返回原点

### 代码

```python3
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        if moves.count("R") != moves.count("L"):
            return False
        if moves.count("U") != moves.count("D"):
            return False
        return True
```