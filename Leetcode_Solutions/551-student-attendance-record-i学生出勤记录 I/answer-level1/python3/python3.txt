### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def checkRecord(self, s: str) -> bool:
        return not( s.count('A') > 1 or "LLL" in s )
```