### 解题思路
遍历,每次遍历时搜索后面第二个字符是不是#

### 代码

```python
class Solution(object):
    def freqAlphabets(self, s):
        """
        :type s: str
        :rtype: str
        """
        res=""
        i=0
        while i < len(s)-2:
            if s[i+2]!='#':
                res=res+chr(ord('a')+int(s[i])-1)
                i+=1
            else:
                res=res+chr(ord('a')+int(s[i:i+2])-1)
                i+=3
        if i==len(s):
            return res
        if s[-1]=='#':
            print i
            res=res+chr(ord('a')+int(s[i:-1])-1)
        else:
            for one in s[i:]:
                res=res+chr(ord('a')+int(one)-1)
        # print res
        return res
```