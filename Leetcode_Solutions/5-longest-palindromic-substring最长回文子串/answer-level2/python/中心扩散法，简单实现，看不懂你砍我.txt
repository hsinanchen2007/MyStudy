### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n=len(s)
        res=""
        #找回文串函数
        def hui(s,left,right):
            while right<n and left>=0 and s[right]==s[left]:
                right+=1
                left-=1
            return s[left+1:right]
        for i in range(n):
            #偶数情况
            res1=hui(s,i,i+1)
            #奇数情况
            res2=hui(s,i,i)
            #比res长，就替换字符串
            if len(res1)>len(res):
                res=res1
            if len(res2)>len(res):
                res=res2
        return res
```