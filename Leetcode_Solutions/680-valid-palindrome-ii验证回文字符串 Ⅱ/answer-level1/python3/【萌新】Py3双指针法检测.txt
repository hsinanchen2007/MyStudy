### 解题思路
双指针检测，从头和尾遍历，如果是回文就继续，不是回文就把这个不是回文的字符去掉，看剩下的是否是回文，分左右两种情况

### 代码

```python3
class Solution:
    def validPalindrome(self, s: str) -> bool:
        i=0
        j=len(s)-1
        while i<j:
            if s[i]==s[j]:
                i+=1
                j-=1
            else:
                str_left=s[:i]+s[i+1:]
                if str_left==str_left[::-1]:
                    return True
                str_right=s[:j]+s[j+1:]
                if str_right==str_right[::-1]:
                    return True
                return False
        return True
```