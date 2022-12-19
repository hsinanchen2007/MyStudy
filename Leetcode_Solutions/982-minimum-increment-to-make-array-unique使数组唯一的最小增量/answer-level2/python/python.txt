### 解题思路
先排序，然后按顺序加差值+1

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        if not A:
            return 0
        
        A = sorted(A)
        res = 0
        pre = A[0]
        for i in range(1, len(A)):
            if A[i] <= pre:
                add_num = pre - A[i] + 1
                A[i] += add_num
                res += add_num
            
            pre = A[i]
        
        return res
```