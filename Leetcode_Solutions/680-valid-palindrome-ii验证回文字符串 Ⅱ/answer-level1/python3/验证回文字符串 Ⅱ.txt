### 解题思路
先遍历原数组，若遇到不等，则分别存储新的字符串，即左边删除一个得到的和右边删除一个得到的字符串，再对这两个字符串进行遍历，若至少有一个符合，则满足。时间o(n),空间o(n)


### 代码

```python3
class Solution:
    def validPalindrome(self, s: str) -> bool:
        if s == "":
            return False
        len_s = len(s)
        half = int((len_s-1)/2)
        new_s1 = ""
        new_s2 = ""
        result1 = 1
        result2 = 1
        for i in range(half+1):
            if s[i] != s[len_s-1-i]:
                new_s1 = s[i:len_s-1-i]
                new_s2 = s[i+1:len_s-i]
                break
        if new_s1 == "" and new_s2 == "":
            return True
        if new_s1 != "":
            len_s = len(new_s1)
            half = int((len_s-1)/2)
            for i in range(half+1):
                if new_s1[i] != new_s1[len_s-1-i]:
                    result1 = 0
        if result1:
            return True
        if new_s2 != "":
            len_s = len(new_s2)
            half = int((len_s-1)/2)
            for i in range(half+1):
                if new_s2[i] != new_s2[len_s-1-i]:
                    result2 = 0
        
        return (result1 or result2)
```