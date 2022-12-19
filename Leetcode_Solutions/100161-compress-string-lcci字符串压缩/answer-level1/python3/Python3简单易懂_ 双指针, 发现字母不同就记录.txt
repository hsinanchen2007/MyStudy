### 解题思路
双指针, j指针字母和i指针字母不同的时候就记录下来, 并且更新i指针到当前j指针位置.

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if len(S) <= 0:
            return S
        i, j = 0, 0
        res = ''
        while j < len(S):
            if S[j] != S[i]:
                res += (S[i] + str(j - i))
                i = j
            j += 1
        res += S[i] + str(j - i)
        if len(res) >= len(S):
            return S
        else:
            return res
```