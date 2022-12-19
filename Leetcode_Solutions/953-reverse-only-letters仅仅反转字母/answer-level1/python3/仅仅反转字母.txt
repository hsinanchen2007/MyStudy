### 解题思路
双指针

### 代码

```python3
class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        S = list(S)
        front, end = 0, len(S) - 1
        while front < end:
            if not S[front].isalpha():
                front += 1
            elif not S[end].isalpha():
                end -= 1
            else:
                S[front], S[end] = S[end], S[front]
                front += 1
                end -= 1
        return ''.join(S)
```