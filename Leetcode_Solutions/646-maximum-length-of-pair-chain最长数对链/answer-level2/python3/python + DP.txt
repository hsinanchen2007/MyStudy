```python
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        # pairs = [[1, 2], [2, 3],[3, 4]]
        # maximum length of pairs
        # a, b => (0, 1000)
        # sorted(pairs)
        # Time complexity O(nlogn) + O(n ** 2)
        # if pair[0] > pre_pair[1]:
        #       dp[i] = max(dp[i], dp[i - 1] + 1)
        if pairs == []: return 0
        pairs.sort(key = lambda x : (x[0], x[1]))
        length = len(pairs)
        dp = [1] * length
        for i in range(1, length):
            for j in range(i):
                if pairs[i][0] > pairs[j][1]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return dp[-1]

```