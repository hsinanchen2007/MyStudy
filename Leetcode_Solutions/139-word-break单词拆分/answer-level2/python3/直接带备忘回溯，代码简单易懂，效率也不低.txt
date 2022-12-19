### 解题思路
步进时按单词列表中出现的单词长度，从小到大进行尝试。

### 代码

```python3
import functools
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wl = sorted(list({len(w) for w in wordDict})) # 得到单词表中的所有可能长度
        vobs = set(wordDict)
        pos, N = 0, len(s)
        @functools.lru_cache()
        def sol(pos) :
            if pos == N : return True
            if pos > N : return False
            for l in wl:
                if s[pos:pos+l] in vobs :
                    if sol(pos+l) : return True
            return False
        return sol(0)
```