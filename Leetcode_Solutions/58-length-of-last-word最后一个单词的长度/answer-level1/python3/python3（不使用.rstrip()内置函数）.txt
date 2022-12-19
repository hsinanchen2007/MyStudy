```python []
class Solution:
    def lengthOfLastWord(self, s: str) -> int:

        lens = len(s)  # 这一块不是很必要，只是用lens来存储长度

        if s and s[lens - 1] == ' ':  #如果s不为空则删除末尾的空格，其实用s.rstrip()即可
            n = lens - 1
            while n >= 0 and s[n] == ' ':
                n -= 1
            s = s[: n + 1]

        if s == '':       #如果s为空或删除空格后为空，则输出0
            return 0

        for i in range(len(s)-1,-1,-1):   #对于删除末尾空格后不为空的情况，向前查找空格，查找到空格就输出对应长度
            if s[i] == ' ':
                return(len(s)-i-1)
        
        return len(s)    # 如果没有查找到空格就输出整个字符串长度
```