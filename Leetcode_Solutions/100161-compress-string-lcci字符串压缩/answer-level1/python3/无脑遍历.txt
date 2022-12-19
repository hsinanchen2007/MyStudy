### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return S
        original = len(S)
        result = S[0]
        count = 1
        for i in range(1, original):
            if S[i] == S[i-1]:
                count += 1
            else:
                result += str(count) + S[i]
                count = 1
        result += str(count)
        return result if len(result) < original else S
```