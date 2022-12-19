### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        rNum = 0
        lNum = 0
        res = 0
        for char in s:
            if char == 'R':
                rNum += 1
            else:
                lNum += 1
            if rNum == lNum:
                res += 1
                rNum = 0
                lNum = 0
        return res
        
```