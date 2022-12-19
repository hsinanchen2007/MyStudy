### 解题思路
将数字转换为字符串，首先负数不符合条件。之后直接反转字符串，将反转后的字符串与原字符串进行比较即可，如果相等返回True，否则返回False

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        s=str(x)
        if x<0:
            return False
        else:
            s1=s[::-1]
            if s1==s:
                return True
            else:
                return False 
```