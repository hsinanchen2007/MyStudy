### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A) -> int:
        ans = 0
        A.sort()
        for i in range(len(A)):
            k = len(A) - 1
            if i+1 <= k:
                # while A[i] >= A[i + 1]:
                #     A[i + 1] += 1
                #     ans += 1
                if A[i] >= A[i + 1]:
                    ans += 1 + A[i] - A[i+1]
                    A[i + 1] = A[i]+1
        return ans

```