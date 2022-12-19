### 解题思路
第一个和第二个if写成这样，比用一个if里用and把两个条件合并在一起更快一点点

### 代码

```python3
class Solution:
    def addDigits(self, num: int) -> int:
        if num == 0:
            return 0
        if num % 9 == 0:
            return 9
        else:
            return num % 9
```