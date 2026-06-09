### 解题思路
使用两个list分别存储str的前n个和其他字符串，使用“+”运算符对两个字符串拼接

### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        lis = s[:n]
        lis_ = s[n:]
        lis_ += lis
        return lis_
        
```