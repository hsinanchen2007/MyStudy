速度没有各位reverse或者[::-1]来的快，但是能体现出解题思想
Python3所有数用long保存，不用担心中间过程会溢出
```
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """

        neg=0
        if x<0:
            neg=1
            x=abs(x)
        l=0
        while (x!=0):
            l=l*10+x%10;
            x//=10;

        if neg==1:
            l= -1*l
        if not -2**31<l<2**31-1:
            return 0
        return l
```
