### 解题思路
用counter统计每个字符出现的次数，遍历s后返回

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> int:
        from collections import Counter
        counter=Counter(s)
        for index,char in enumerate(s):
            if counter[char]==1:
                return index
        return -1

      
```