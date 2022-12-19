```
class Solution(object):
    def findDerangement(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==1:
            return 0
        if n==2:
            return 1
        pre=0
        cur=1
        for i in range(3,n+1):
            pre,cur=cur,(i-1)*(pre+cur) % (10**9+7)
        return cur
```


假设第一个数选择位置为x，有（n-1）个可选位置。对于x，可选择1或者其他位置：选择1，则对剩下的（n-2）个数字错位排列；选择其他位置，等价于（n-1）个数字错位排列