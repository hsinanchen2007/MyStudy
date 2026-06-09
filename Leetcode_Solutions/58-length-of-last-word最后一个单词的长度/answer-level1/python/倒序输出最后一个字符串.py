### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if s.split()==[]:
            return 0
        else:
            s=s.split()
            return len(s[-1])
```