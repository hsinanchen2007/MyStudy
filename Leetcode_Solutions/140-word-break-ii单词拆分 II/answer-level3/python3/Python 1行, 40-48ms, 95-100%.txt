仅供娱乐
```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        return (lambda dp, i: dp(dp,i,set(wordDict),set(map(len,wordDict))))(lambda dp, i, wordDict, lengths, cache = {len(s): ['']}: cache[i] if i in cache else [s[i:i+l] + (ws and ' ' + ws) for l in lengths if s[i:i+l] in wordDict for ws in cache.setdefault(i+l, dp(dp, i+l, wordDict, lengths, cache))], 0)
```
