### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip(' ')
        if s == "":
            return 0
        return len(s.split(' ')[-1])
```