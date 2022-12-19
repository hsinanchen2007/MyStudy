### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def twoSumLessThanK(self, A: List[int], K: int) -> int:
        A.sort()
        i, j = 0, len(A)-1
        res = -1
        while i<j:
            if A[i]+A[j]<K:
                res = max(res,A[i]+A[j])
                i += 1
            elif A[i]+A[j]>=K:
                j -= 1
        return res
            
        
```