### 解题思路
1:判断是否为负数，若是->返回False
2:判断翻转后的数字是否等于原来数字，
若是，返回True
否则返回False
### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        else:
            if int(str(x)[::-1])==x:
                return True
            else:
                return False
```