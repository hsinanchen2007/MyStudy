### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        from collections import Counter
        res = 0
        cnt = Counter(chars)
        for i in words:
            c = Counter(i)
            if all(c[ii] <= cnt[ii] for ii in c):
                res += len(i)
        return res
```