### 解题思路
两个条件均满足则有奖励：
1. A次数最多为1
2. 不包含3个连续L

### 代码

```python3
class Solution:
    def checkRecord(self, s: str) -> bool:
        if 'LLL' in s:
            return False
        countA = 0
        for i in range(len(s)):
            if s[i] == 'A':
                countA += 1
        
        if countA > 1:
            return False
        else:
            return True

        # 可简写为：return not(len(s.split('A'))>2 or "LLL" in s)  
```