### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        return (True if str(x)[::-1]==str(x) else False) if x>=0 else False
```