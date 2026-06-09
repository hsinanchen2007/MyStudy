### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        from collections import Counter 
        cnt = Counter(chars)
        res = 0
        for i in words:
            c = Counter(i)
            if all(c[x] <= cnt[x] for x in i):
                res += len(i)
        return res
```