### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        dict={}
        for i in s:
            if i not in dict:
                dict[i]=1
            else:
                dict[i]=dict[i]+1
        ans=0
        jihao=0
        for i in dict:
            if dict[i]%2==0:
                ans=ans+dict[i]
            else:
                ans=ans+dict[i]-1
                jihao=1
        ans=ans+jihao
        return ans
```