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
        num = 0
        sin2 = 0
        for i in range(len(s)-1,-1,-1):
            if s[i] != ' ':
                sin2 = i
                break    
        for i in range(len(s)):
            if s[i] == ' 'and i!=(sin2 +1):
                num = 0
            elif i == sin2 +1 and s[i]==' ':
                return num
            else:
                num = num + 1
        #if  sin == 0:
            #return 0
        return num   
```