### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
        return '%20'.join(s.split(" "))
```