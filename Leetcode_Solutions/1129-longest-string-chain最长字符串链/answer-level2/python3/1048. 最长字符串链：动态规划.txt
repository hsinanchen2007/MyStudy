
```python []
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        ans, dp = 0, collections.defaultdict(int)
        for w in sorted(words, key=len):
            for i in range(len(w)):
                dp[w] = max(dp[w], dp[w[: i] + w[i + 1:]] + 1)
            ans = max(ans, dp[w])
        return ans
```