### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        p=0
        q=len(s)-1
        tmp=0
        while p<=q:
            if s[p]!=s[q]:
                p1=p+1
                q1=q
                p2=p
                q2=q-1
                while p1<=q1:
                    if s[p1]!=s[q1]:
                        tmp+=1
                        break
                    p1+=1
                    q1-=1
                while p2<=q2:
                    if s[p2]!=s[q2]:
                        tmp+=1
                        break
                    p2+=1
                    q2-=1
                return tmp<2
            p+=1
            q-=1
        return True
                
```