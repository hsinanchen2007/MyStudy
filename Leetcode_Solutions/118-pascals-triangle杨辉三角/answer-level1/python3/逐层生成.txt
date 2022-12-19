```
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res = []
        for i in range(numRows):
            cur = [1 for j in range(i+1)]
            for j in range(1,i):
                cur[j] = res[i-1][j-1] + res[i-1][j]
            res.append(cur)
        return res
```
