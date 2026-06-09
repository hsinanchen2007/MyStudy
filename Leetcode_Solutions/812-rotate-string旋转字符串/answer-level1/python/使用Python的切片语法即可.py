### 解题思路
A[idx:]+A[:idx]
这个方法，可以从idx做拆分，把两个子字符串合并

### 代码

```python3
class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        if A == B:
            return True
        for idx in range(len(A)):
            new_str = A[idx:]+A[:idx]
            if new_str == B:
                return True
        return False
```