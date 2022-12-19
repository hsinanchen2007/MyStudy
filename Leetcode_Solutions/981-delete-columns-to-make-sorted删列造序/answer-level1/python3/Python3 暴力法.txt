### 解题思路
对表里面的每一列，找到是否有一个降序存在，如果存在，res加1，跳出内循环继续执行。
### 代码

```python3
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        res = 0
        for i in range(len(A[0])):
            for j in range(1, len(A)):
                if A[j][i] < A[j-1][i]:
                    res += 1
                    break
        return res  
```