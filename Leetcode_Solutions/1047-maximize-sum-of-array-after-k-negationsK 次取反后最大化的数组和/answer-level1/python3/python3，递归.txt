# 解题思路
递归
# 代码
```
class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        if K==0:
            return sum(A)
        else:
            tmp = min(A)
            index = A.index(tmp)
            A[index] = -A[index]
            return self.largestSumAfterKNegations(A,K-1)
```
# 性能
![image.png](https://pic.leetcode-cn.com/a8559db7476ba283322a37e87675a4de11d299fbb674eb42094201d9129fd7af-image.png)
