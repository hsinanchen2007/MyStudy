### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def checkRecord(self, s: str) -> bool:
        absent = 0
        l = 0
        for i, x in enumerate(s):
            if x == 'A':
                l = 0
                absent += 1
                if absent == 2:
                    return False
            elif x == 'L':
                l += 1
                if l == 3:
                    return False
            else:
                l = 0
        return True
```