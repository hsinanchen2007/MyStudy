### 解题思路
考虑K和数组中负数的大小

### 代码

```python
class Solution(object):
    def largestSumAfterKNegations(self, A, K):
        negative = 0
        for a in A:
            if a < 0:negative += 1
        sum1 = 0
        if K >= negative:
            for i in range(len(A)):
                if A[i] < 0:
                    A[i] = -A[i]
                sum1 += A[i]
            A.sort()
            if (K - negative) % 2 == 0:return sum1  #补偿了所有的负数后，剩余的反转次数若为偶数，则相当于0，若为奇数，则去翻转补偿后数组的最小值
            else:return sum1 - 2 * A[0]
        else:
            A.sort()
            for i in range(K):
                if A[i] < 0:
                    A[i] = -A[i]
                sum1 += A[i]
            for i in range(K,len(A)):
                sum1 += A[i]
            return sum1
```