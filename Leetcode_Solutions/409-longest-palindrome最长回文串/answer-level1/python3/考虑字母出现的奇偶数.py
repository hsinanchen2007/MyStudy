### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        l = list(set(s)) #无重复字母列表
        r = 0            #计数
        if len(l) == 1:  #边界：相同字母的情况
            return len(s)
        else:
            for i in range(len(l)):
                c = s.count(l[i]) #统计原字符串中字母个数
                if ((c % 2) == 0):
                    r += c
                if ((c % 2) == 1):
                    r += c-1
            if r == len(s)   :
                return r
            return r+1  #考虑字符串为回文串
            
```