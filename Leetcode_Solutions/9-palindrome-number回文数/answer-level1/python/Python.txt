### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x==0:
            return True
        if x<0:return False
        if x%10==0:
            return False
        l=x
        r=0
        while(l>r):
            r=r*10+l%10
            l=l/10
        if l==r:
            return True
        if l==r/10:
            return True
        return False
```