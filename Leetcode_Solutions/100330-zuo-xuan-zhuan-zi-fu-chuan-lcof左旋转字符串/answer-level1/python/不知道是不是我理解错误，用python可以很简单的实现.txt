### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def reverseLeftWords(self, s, n):
        return s[n:] + s[:n]
```