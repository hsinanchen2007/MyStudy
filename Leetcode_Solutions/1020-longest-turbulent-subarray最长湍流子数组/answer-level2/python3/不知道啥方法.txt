### 解题思路
每次比较，把状态记录下来，下次比较的时候就可以和这个状态作对比，就可以判断输出是否该加一了。

### 代码

```python3
class Solution:
    def maxTurbulenceSize(self, A: List[int]) -> int:
            nums = len(A)
            if nums==1:
                return 1
            res_n = 1
            final = 1
            state = 0
            for i in range(1,nums):
                if A[i] == A[i-1]:
                    state = 0
                    res_n = 1
                elif (A[i] > A[i-1]):
                    if state <= 0:
                        res_n += 1
                    else:
                        res_n = 2
                    state = 1
                else:
                    if state >= 0:
                        res_n += 1
                    else:
                       
                        res_n = 2
                    state = -1
                 final = max(res_n, final)
            return final

```