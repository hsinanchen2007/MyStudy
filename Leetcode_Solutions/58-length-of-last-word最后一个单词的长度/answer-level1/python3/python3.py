### 解题思路
先去空格再分词

### 代码

```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s=s.strip()
        res=s.split(" ")
        return len(res[-1]) if res else 0
```