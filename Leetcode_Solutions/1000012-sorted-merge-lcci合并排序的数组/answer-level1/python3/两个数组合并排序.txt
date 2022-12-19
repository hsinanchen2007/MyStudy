### 解题思路
对于两个数组，首先分别排序，然后对比两个数组最小值，将更小的储存到合并数组中。
注意边界值。

### 代码

```python3
class Solution:
    def merge(self, A, m, B, n):
        B.sort()
        C=A[0:m]
        C.sort()
        cp=0
        bp=0
        for i in range(m+n):
            if bp==n:
                A[i:]=C[cp:]
                break
            elif cp==m:
            	A[i:]=B[bp:]
            	break
                # for x in range(m+n-i):
                #     A[x]=B[n-bp-x]
            if B[bp]<=C[cp]:
                A[i]=B[bp]
                bp+=1
            else:
                A[i]=C[cp]
                cp+=1
```