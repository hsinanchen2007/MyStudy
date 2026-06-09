### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def checkRecord(self, s: str) -> bool:
        if s.count("A")<=1 and s.find("LLL")==-1:
            return True
        return False
```