O(n^3)速度一般，还是贪心单调栈厉害点。

```
class Solution(object):
    def mctFromLeafValues(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        n = len(arr)
        
        f_max = {}
        def fMax(i, j):
            if (i, j) in f_max:
                return f_max[(i, j)]
            elif i==j:
                f_max[(i,i)] = arr[i]
                return arr[i]
            else:
                k = (i + j) >> 1
                f_max[(i, j)] = max(fMax(i, k), fMax(k + 1, j))
                return f_max[(i, j)]
            
        for i in range(n):
            for j in range(i,n):
                fMax(i, j)

        f_ans = {}
        def fAns(i = 0, j = n - 1):
            if (i, j) in f_ans:
                return f_ans[(i, j)]
            elif j == i:
                f_ans[(i, i)] = 0
                return 0
            elif i + 1 == j:
                f_ans[(i, j)] = arr[i] * arr[j]
                return f_ans[(i, j)]
            else:
                f_ans[(i, j)] = min([fAns(i, k) + fAns(k+1, j) + f_max[i, k] * f_max[k+1, j] for k in range(i, j)])
                return f_ans[(i, j)]
        
        return fAns()
```
