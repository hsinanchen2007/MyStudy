### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s)==0:
            return 0
        exist=False
        i=0
        j=0
        #alpha='abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
        for i in range(len(s)):
            if s[i]!=' ':
                exist=True
                break
        if exist==False:
            return 0
        j=i
        s+=' '
        count=0
        while j<len(s):
            if s[j]==' ':
                count+=1
                i=j+1
                while i<len(s):
                    if s[i]!=' ':
                        break
                    #else:
                    i+=1
                if i==len(s):
                    break
                #else:
                j=i
            j+=1
        return count
```