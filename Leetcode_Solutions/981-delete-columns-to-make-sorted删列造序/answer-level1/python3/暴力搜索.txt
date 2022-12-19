### 解题思路
时间复杂度：O（mn）
空间复杂度：O（n）

### 代码

```python3
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        if not A:
            return 0
        col = len(A[0])
        row = len(A)
        count = 0
        for i in range(col):
            temp_s = [A[j][i] for j in range(row)]
            if not self.is_acend(temp_s):
                count += 1
        return count

    def is_acend(self, s):
        if not s:
            return False
        if len(s) == 1:
            return True
        last_s = s[0]
        for ind, i in enumerate(s):
            if ind == 0:
                continue
            if i < last_s:
                return False
            last_s = i
        return True
```