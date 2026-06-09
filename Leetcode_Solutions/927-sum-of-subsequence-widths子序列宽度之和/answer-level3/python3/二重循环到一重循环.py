### 解题思路

首先要想到排序后结果不变

第一种推了推，发现超时。比如计算1，2，3，4、
对排序后的递推结果。以4为例
4的话，1遇到4次，2遇到2次，3遇到1次。

第二种方法的话，是统计左右边界的数量，一个是2**n一个是2**(n-i-1)
用移位会更快一点

### 代码

```python3
class Solution:
    def sumSubseqWidths(self, A: List[int]) -> int:
        # '' 1
        # '' 1 2 12
        # '' 1 2 12 3 13 23 123  ->6
        # '' 1 2 12 3 13 23 123 4 14 24 124 34 134 234 1234 -> 6 + 

        res = 0
        n = len(A)
        A = sorted(A)
        # for i in range(n):
        #     for j in range(i):
        #         res += (1 << (i-j-1)) * (A[i] - A[j])
        for i in range(n):
            res = res + ((1 << i) - (1 << (n-i-1)) ) * A[i]
        return res % int(1e9+7)

```