### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        res = 1  # 递增标志
        for i in range(1, len(A)):
            if A[i] >= A[i - 1]:
                continue
            else:
                res = -1
                break
        if res == 1:return True
        for i in range(1, len(A)):
            if A[i] <= A[i - 1]:
                continue
            else:
                return False
        return True



```