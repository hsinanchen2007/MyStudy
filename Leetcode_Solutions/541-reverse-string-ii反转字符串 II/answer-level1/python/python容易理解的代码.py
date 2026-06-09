### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        res=''
        tmp=0
        while tmp+2*k<len(s):
            res=res+s[tmp:tmp+k][::-1]
            res=res+s[tmp+k:tmp+2*k]
            tmp+=2*k
        if tmp+k<len(s):
            res=res+s[tmp:tmp+k][::-1]
            res=res+s[tmp+k:]
        else:
            res=res+s[tmp:][::-1]
        return res
```