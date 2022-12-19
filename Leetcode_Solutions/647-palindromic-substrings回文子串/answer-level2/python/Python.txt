### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans=0
        for i in range(len(s)):
            l=i
            r=i
            while l>=0 and r<len(s) and s[l]==s[r]:
                l=l-1
                r=r+1
                ans=ans+1
            l=i
            r=i+1
            while l>=0 and r<len(s) and s[l]==s[r]:
                l=l-1
                r=r+1
                ans=ans+1
        return ans
```