### 解题思路
开始想到先转字符串，再做处理

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        s = str(x)
        if x < 0 :
            return False
        elif 0 <= x <10:
            return True          
        return s == s[::-1] 
```