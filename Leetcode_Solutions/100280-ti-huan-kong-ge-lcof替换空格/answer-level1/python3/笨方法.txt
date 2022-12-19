### 解题思路
使用str的replace方法替换空格

### 代码

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
        return s.replace(' ','%20')
```