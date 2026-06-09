### 解题思路
双指针法：从左边的第一个数开始向中心走，同时右边的最后一个数也开始向中心走。如果左边的索引值小于右边，就证明还没有指到中心，然后再判断是不是数字或者字母，如果相等，就继续走到中心。如果不相等，就直接输出false。如果不是字母或数字，可能是空格，于是继续两边索引值继续往中心走。

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        i=0
        j=len(s)-1
        while i < j:
            if s[i].isalnum() and s[j].isalnum():
                if s[i].upper() == s[j].upper():
                    i+=1
                    j-=1
                else:
                    return False
            elif not s[i].isalnum():
                    i+=1
            elif not s[j].isalnum():
                    j-=1
        return True
```