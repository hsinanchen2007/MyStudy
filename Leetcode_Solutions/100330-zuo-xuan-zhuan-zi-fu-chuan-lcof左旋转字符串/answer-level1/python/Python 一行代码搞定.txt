### 解题思路
直接拼成s+s,返回对应下标序列即可

### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        return (s+s)[n:n+len(s)]
```