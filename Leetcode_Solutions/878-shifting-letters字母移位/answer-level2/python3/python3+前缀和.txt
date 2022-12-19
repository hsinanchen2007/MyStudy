### 解题思路
不知道为啥效率很低

### 代码

```python3
class Solution:
    def shiftingLetters(self, S: str, shifts: List[int]) -> str:
        for i in range(len(shifts)-2,-1,-1):
            shifts[i] += shifts[i+1]
        s = list(S)
        for i in range(len(s)):
            s[i] = chr((ord(s[i]) + shifts[i] - 97)%26 + 97)
        return ''.join(s)
```