### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        num = 0
        for i in range(len(s)-1,-1,-1):
            if s[i]!=' ':
                num = num +1
            elif num!=0 :
                break
        return num
```