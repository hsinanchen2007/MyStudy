### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        res=0
        index=len(s)-1
        while  index>0 and s[index]==' ' :
            index-=1
        for i in range(index,-1,-1):
            if s[i]==' ':
                return res
            else:
                res+=1
        return res
```