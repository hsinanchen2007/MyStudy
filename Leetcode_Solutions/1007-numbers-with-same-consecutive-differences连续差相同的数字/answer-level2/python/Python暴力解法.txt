将数字转化成字符串、再将字符串转化成数字
```
class Solution:
    def numsSameConsecDiff(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: List[int]
        """
        if N==1:
            return [i for i in range(10)]
        smaller=[str(i) for i in range(1,10)]
        while len(smaller[0])<N:
            s=smaller.pop(0)
            if int(s[-1])+K<10:
                s1=str(int(s[-1])+K)
                smaller.append(s+s1)
            if int(s[-1])-K>=0:
                s2=str(int(s[-1])-K)
                smaller.append(s+s2)
        res=[int(i) for i in smaller]
        return list(set(res))
```
