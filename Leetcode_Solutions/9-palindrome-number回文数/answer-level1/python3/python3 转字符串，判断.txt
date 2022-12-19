### 解题思路
str(x) == str(x)[::-1]

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        return str(x) == str(x)[::-1]
```