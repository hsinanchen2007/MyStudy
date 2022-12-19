### 解题思路
注释处写明了解题思路

### 代码

```python3
class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        neg_num = 0#先将令负数的个数初始化为0
        A.sort()
        for i in A:#得到A中负数的个数
            if i<0:
                neg_num+=1
        if K<neg_num:#如果K的个数小于负数的个数，相当于将最小的K个数变为相反数即可
            for i in range(K):
                A[i] = -A[i]
        if K>=neg_num:#如果K的个数大于负数的个数，说明需要将一部分变为正再变为负
            if (K-neg_num)%2==0:#如果K与负数个数的差可以被2整除，负负得正相当于没变
                for i in range(neg_num):#
                    A[i] = -A[i]
            else:#如果K与负数个数的差不可以被2整除，那就需要将排序后最小的数变为其相反数再求和
                for i in range(neg_num):
                    A[i] = -A[i]
                A.sort()
                A[0] = -A[0]
        return sum(A)


```