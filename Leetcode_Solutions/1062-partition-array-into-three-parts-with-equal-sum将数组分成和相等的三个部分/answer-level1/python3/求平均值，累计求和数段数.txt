```
class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        total = sum(A)/3
        count = 0
        num = 0
        for i in A:
            num += i
            if num == total:
                num = 0
                count += 1
        return count == 3
```
