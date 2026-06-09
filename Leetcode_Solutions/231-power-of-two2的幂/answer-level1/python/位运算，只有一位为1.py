### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        res=0
        while n>0:
            res+=n&1
            n=n>>1
        return res==1
```