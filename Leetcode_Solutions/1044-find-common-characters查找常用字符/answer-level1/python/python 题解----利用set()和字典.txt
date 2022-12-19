```
class Solution(object):
    def commonChars(self, A):
        """
        :type A: List[str]
        :rtype: List[str]
        """
        dic = {}
        num = []
        result = []
        for i in set(A[0]):
            for j in A:
                num.append(j.count(i))
            dic[i] = min(num)
            num = []
        print(dic)
        for i,j in dic.items():
            if j != 0:
                for k in range(j):
                    result.append(i)
        return result
```
