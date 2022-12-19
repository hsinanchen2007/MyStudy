### 解题思路
用哈希表

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> int:
        map = collections.Counter(s)
        if all([map[key] != 1 for key in map]):
            return -1
        
        for index,char in enumerate(s):
            if map[char] == 1:
                return index
        
```