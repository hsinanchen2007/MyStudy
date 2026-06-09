### 解题思路
此处撰写解题思路

### 代码

```python
class Solution:
    def isPalindrome(self, x: int) -> bool:
        return str(x) == str(x)[::-1]
```

```python
class Solution:
    def isPalindrome(self, x: int) -> bool:
        """未通过测试"""
        if x < 0: return False
        ranger = 1
        while x //ranger >= 10:
            ranger *= 10
        # print(ranger)
        while x:
            left = x // ranger 
            right = x % 10 
            if left != right:
                return False

            x = (x // ranger) % 10
            ranger //= 100
        return True

```
