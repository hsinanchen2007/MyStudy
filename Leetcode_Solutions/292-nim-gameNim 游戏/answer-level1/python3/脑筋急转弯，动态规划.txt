
S1: 脑筋急转弯
1,2,3,4,5,6,7,8 = T,T,T,F,T,T,T,F
```
class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return (n % 4 != 0)
```
S2: 动态规划
```
class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n == 1 or n == 2 or n == 3: return True
        n0, n1, n2 = True, True, True
        for i in range(3,n):
            if (n0 and n1 and n2):
                n0, n1, n2 = n1, n2, False
            else:
                n0, n1, n2 = n1, n2, True
        return n2
```