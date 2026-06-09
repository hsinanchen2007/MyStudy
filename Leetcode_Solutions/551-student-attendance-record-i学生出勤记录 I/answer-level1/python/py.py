### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        a=0
        l=0
        for char in s:
            if char=='A':
                a+=1
            if char=='L':
                l+=1
            if a>1:
                return False
        if l<=2:
            return True
        for i in range(len(s)):
            if s[i]=='L':
                break
        j=i+1
        while i<len(s)-2:
            if s[i:i+3]=='LLL':
                return False
            i+=1
        return True




```