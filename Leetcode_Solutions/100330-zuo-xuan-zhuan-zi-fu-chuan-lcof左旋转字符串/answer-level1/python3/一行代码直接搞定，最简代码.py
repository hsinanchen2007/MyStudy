### 解题思路
看到这个题目，我想到的就是字符串的切片方法，一行搞定

### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        return s[n:]+s[:n]
```