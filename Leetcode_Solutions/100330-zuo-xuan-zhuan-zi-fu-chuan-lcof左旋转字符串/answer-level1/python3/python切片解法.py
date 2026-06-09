### 解题思路
获取s的下标，在s等于n的时候进行切片。

### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        for i in range(len(s)):
            if i == n:
                temp = s[:n]
                s = s[n:] + temp
                return s
```