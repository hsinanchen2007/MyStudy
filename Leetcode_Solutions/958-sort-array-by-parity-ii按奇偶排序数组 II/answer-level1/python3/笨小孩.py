```
class Solution(object):
    def sortArrayByParityII(self, A:list):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        a = [i for i in A if i % 2]
        b = [i for i in A if not i % 2]
        for i in range(1, len(A), 2):
            for j in a:
                b.insert(i, j)
                del a[0]
                break
        return b
```
