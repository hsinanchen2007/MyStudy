### 解题思路
切片反转字符串

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        return str(x)[::-1] == str(x)
```