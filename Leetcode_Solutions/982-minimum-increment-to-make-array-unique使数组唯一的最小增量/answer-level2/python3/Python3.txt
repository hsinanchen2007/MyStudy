### 解题思路
排序

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        # 1. 集合 超时
        # res, num_set = 0, set()
        # for i in A:
        #     if i not in num_set:
        #         num_set.add(i)
        #     else:
        #         while i in num_set:
        #             i += 1
        #             res += 1
        #         num_set.add(i)
        # return res
                
        # 2. 先排序
        res = 0
        A.sort()
        for i in range(1, len(A)):
            if A[i] <= A[i-1]:
                res += (A[i-1] - A[i] + 1)
                A[i] = A[i-1] + 1
        return res
```