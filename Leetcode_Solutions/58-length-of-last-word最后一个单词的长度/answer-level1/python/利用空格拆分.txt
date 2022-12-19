### 解题思路
时间复杂度：O（n）
时间复杂度：O（1）

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = s.split(" ")
        for i in range(len(words)-1, -1, -1):
            import re
            if words[i] and len(re.findall("\w", words[i])) == len(words[i]):
                return len(words[i])
        return 0
```