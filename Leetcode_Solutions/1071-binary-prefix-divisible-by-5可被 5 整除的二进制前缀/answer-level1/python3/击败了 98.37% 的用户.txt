### 解题思路


### 代码

```python3
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        ans = [False] * len(A)
        tmp = 0
        for i in range(len(A)):
            tmp =(tmp * 2 + A[i]) % 5
            ans[i] = (tmp == 0)
        return ans

```