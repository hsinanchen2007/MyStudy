### 解题思路
mis指向第二小的元素
每次翻转后只需要将A[0]与A[mins]比较

### 代码

```python
class Solution(object):
    def largestSumAfterKNegations(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        A = sorted(A)
        mins = 1
        for i in range(K):
            A[0] = -A[0]
            if A[0] > A[mins]:
                A[0], A[mins] = A[mins], A[0]
                mins += 1
        return sum(A)



```