### 解题思路
1: 用到了字符串翻转切片，首先，把int类型转换成str类型
2: str类型字符串翻转，翻转前后相等，则就是true，否则是false

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        newx = str(x)[::-1]
        if newx == str(x):
            return True
        else:
            return False
```