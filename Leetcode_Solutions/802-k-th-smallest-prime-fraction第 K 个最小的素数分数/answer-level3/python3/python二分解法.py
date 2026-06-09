python 二分解法，难点主要在于不能显示存储二维矩阵
其实分数比较大小一般有两种方法，一种是本次使用的分子分母相乘相减，另一种是浮点数比较大小，记录下可能出现的分数的最小差值，只要差值小于这个最小差值，就把他判为相等即可
```
class Solution:
    def kthSmallestPrimeFraction(self, A: List[int], K: int) -> List[int]:
        total = (len(A)-1)*len(A)/2
        left = (A[0],A[-1])
        right = (0,1)

        def findmidk(matrix: List[int], fenzi: int, fenmu: int):
            i = len(matrix) - 2
            j = 0
            res = 0
            res2 = (0,1)
            while j < len(matrix)-1 and i >= 0:
                if matrix[j]*fenmu - matrix[-i-1]*fenzi <= 0:
                    if res2[1]*matrix[j] - res2[0]*matrix[-i-1] > 0:
                        res2 = (matrix[j],matrix[-i-1])
                    res += (i + 1)
                    j += 1        
                else:
                    i -= 1
            return res,res2

        for i in range(len(A)-1):
            if right[1]*A[i] - right[0]*A[i+1] > 0:
                right = (A[i],A[i+1])
        re = left
        if K == total:
            return list(right)
        while left[0]*right[1] < right[0]*left[1]:
            fenzi = left[0]*right[1] + right[0]*left[1]
            fenmu = left[1]*right[1]*2
            num,re = findmidk(A,fenzi,fenmu)
            if num < K:
                left = (fenzi+1,fenmu)
            elif num > K:
                right = (fenzi,fenmu)
            else:
                break
        return list(re)
```

