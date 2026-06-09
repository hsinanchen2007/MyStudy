i,j分别表示窗口起止位置，初始窗口[0,0]
max_sub_str记录最长回文子串
isReflect(s)判断子串是否回文

开始滑动窗口
如果当前窗口是回文的，判断当前回文窗口长度，如果比最大回文子串长，更新最大回文子串；窗口右+1；
如果当前窗口不是回文的，分别判断基于当前窗口右+1/左减1/左减1&右加1的新窗口是否回文，如果是回文的，则更新窗口起止位置，否则，左+1

滑动窗口有两个要注意的关键点：
1. 就是当起止位置相同时，这个时候的子串是空字符串，是回文的。这个在滑动窗口刚开始的时候会用到。
1. 另一个点就是起止位置相差1的时候，即子串是一个字符的时候，这时窗口是回文的，这个在如下场景会用到：
    - 当窗口右侧进入一个新字符而导致窗口右+1/左减1/左减1&右加1调整，仍然不回文时，最后经过左+1循环几次，窗口左侧最终会达到i=j-1的位置，且i的位置上是刚刚新进入的新字符。
这时又开始一个新的循环查找新的回文子串。

```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        max_sub_str = ''
        i, j = 0, 0
        while j <= len(s):
            if self.isReflect(s[i:j]):
                if j-i > len(max_sub_str):
                    max_sub_str = s[i:j]
                j += 1
            else:
                if self.isReflect(s[i:j+1]):
                    j += 1
                elif i-1 >=0 and self.isReflect(s[i-1:j]):
                    i -= 1
                elif i-1 >=0 and self.isReflect(s[i-1:j+1]):
                    i -= 1
                    j += 1
                else:
                    i += 1
        return max_sub_str
           
    def isReflect(self, s):
        if s == s[::-1]:
            return True
        return False
```
