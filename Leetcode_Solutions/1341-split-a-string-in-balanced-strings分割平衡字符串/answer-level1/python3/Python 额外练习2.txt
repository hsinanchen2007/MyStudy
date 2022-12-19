### 解题思路
无

### 代码

```python3
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        num_L=0
        num_R=0
        count=0
        for i in range(len(s)):
            if s[i]=='L':
                num_L+=1
            else:
                num_R+=1
            if num_L == num_R:
                num_L=0
                num_R=0
                count += 1
        return count

```