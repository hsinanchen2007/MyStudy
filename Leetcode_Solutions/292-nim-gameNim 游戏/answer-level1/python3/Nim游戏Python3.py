### 解题思路
此处撰写解题思路
如果这个数不能被4整除，先手就赢，反之后手赢

### 代码

```python3
class Solution:
    def canWinNim(self, n: int) -> bool:
        if n % 4 == 0:
            return False
        else:
            return True
```