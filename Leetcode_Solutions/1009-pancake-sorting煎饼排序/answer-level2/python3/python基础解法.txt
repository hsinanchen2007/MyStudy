### 解题思路
先找到最大值的index，然后将其翻转到第一位，然后在翻转到最后一位

### 代码

```python3
class Solution:
    def pancakeSort(self, A: List[int]) -> List[int]:
        i, res = len(A), []
        while i > 0:
            max_idx = A[:i].index(i)
            if max_idx != i-1:
                A[:max_idx+1] = A[:max_idx+1][::-1]
                A[:i] = A[:i][::-1]
                res.extend([max_idx+1, i])
            i +=-1
        return res
```