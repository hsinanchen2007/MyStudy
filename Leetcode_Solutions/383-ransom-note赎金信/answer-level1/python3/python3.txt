### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        r = list(ransomNote)
        m = list(magazine)
        for i in r:
            if i not in m:
                return False
            if i in m:
                m.remove(i)
        return True
```