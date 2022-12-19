```
class Solution(object):
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        L = []
        for i in range(left, right + 1):
            flag = 0
            for j in str(i):
                if int(j) == 0 or int(i) % int(j)!= 0:
                    flag = 1
                    break
            if flag == 0:
                L.append(i)
        return L
```
