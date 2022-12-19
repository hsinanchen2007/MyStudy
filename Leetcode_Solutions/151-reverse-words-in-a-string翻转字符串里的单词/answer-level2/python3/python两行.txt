巧妙使用python中数组的切片和连接操作，对于字符的处理很简洁。
```python
class Solution:
    def reverseWords(self, s: str) -> str:
        res = s.strip().split()
        return ' '.join(res[::-1])
```
