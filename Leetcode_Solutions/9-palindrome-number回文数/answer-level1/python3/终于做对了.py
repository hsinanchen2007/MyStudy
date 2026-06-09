### 解题思路
看了几遍回文数的题目   

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x <0:
            return False
        rev = 0
        temp = x
        while x >0:
            p = int(x%10)
            x = int(x/10)
            rev = rev*10 + p
        if rev == temp:
            return True
        else:
            return False

```