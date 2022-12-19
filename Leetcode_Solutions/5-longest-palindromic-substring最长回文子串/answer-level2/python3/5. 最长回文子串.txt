### 解题思路
**白话：**
    滑动窗口 找回文核心，再往两边延伸找到最大的回文。

**伪代码思想：**
存放回文lst
当只有一个字符时，直接返回s
字符串s，从第0个字符到第len(s)-1字符:
    取第i个字符:
        left=0 right=0
    如果第i个字符 == 第i+1个字符
        left=i right=i+1
        while right<len(s) and left>-1:
            if s[left] == s[right]:
                left = left - 1
                right = right - 1
        则s[left+1:right]一定是回文，放入lst
    如果第i个字符 == 第i+2个字符
        left=i right=i+1
        while right<len(s) and left>-1:
            if s[left] == s[right]:
                left = left - 1
                right = right - 1
        则s[left+1:right]一定是回文，放入lst
处理lst找出最长回文子串返回

### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        lst = []
        if len(s) < 2:
            return s
        if len(s) == 2:
            if s[0] == s[1]:
                return s
            else:
                return s[0]
        for i in range(len(s)):
            if i+1 < len(s):
                if s[i] == s[i+1]:
                    left = i
                    right = i+1
                    while right<len(s) and left>-1:
                        if s[left] != s[right]:
                            break
                        left = left - 1
                        right = right +1
                    lst.append(s[left+1: right])
            if i+2 < len(s):
                if s[i] == s[i+2]:
                    left = i
                    right = i+2
                    while right<len(s) and left>-1:
                        if s[left] != s[right]:
                            break
                        left = left - 1
                        right = right +1
                    lst.append(s[left+1: right])
            
        # 对lst进行处理，取出最长的返回
        if lst:
                
            maxlen = 0
            maxind = 0
            for i in range(len(lst)):
                if len(lst[i]) > maxlen:
                    maxlen = len(lst[i])
                    maxind = i 
            return lst[maxind]
        else:
            return ""
```