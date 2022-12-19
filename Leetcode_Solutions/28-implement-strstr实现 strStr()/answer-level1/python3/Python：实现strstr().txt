### 解题思路
方法一：正则表达式
此时不用更待何时，但是时空复杂度O(n*2)和O(n+m)是真的差

### 代码

```python3
import re
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        result=re.search(needle,haystack)
        return result.span()[0] if result else -1
```

### 解题思路
方法二：内置函数
find(),Python和cpp独有函数
index(),好像是Python独有的
时空复杂度都有进步，但是我不知道内部是什么原理
KMP？红黑树？

### 代码
```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.index(needle) if needle in haystack else -1
```

### 解题思路
方法三：KMP

### 代码
```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        def get_next(p): 
            _next = [0] * (len(p)+1) 
            _next[0] = -1            
            i, j = 0, -1
            while (i < len(p)):
                if (j == -1 or p[i] == p[j]):
                    i += 1
                    j += 1 
                    _next[i] = j
                else:
                    j = _next[j]
            return _next
        
        def kmp(s, p, _next):
            i, j = 0, 0
            while (i < len(s) and j < len(p)):
                if (j == -1 or s[i] == p[j]):
                    i += 1
                    j += 1
                else:
                    j = _next[j]
            if j == len(p):
                return i - j
            else:
                return -1 
        return kmp(haystack, needle, get_next(needle))
```

### 解题思路
还没写的：
KMP
BM