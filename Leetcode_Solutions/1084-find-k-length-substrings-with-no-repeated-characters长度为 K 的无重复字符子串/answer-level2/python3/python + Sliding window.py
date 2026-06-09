```python
class Solution:
    def numKLenSubstrNoRepeats(self, S: str, K: int) -> int:
        if K > len(S): return 0
        char_dict = collections.defaultdict(int)
        res = 0
        # Time complexity: O(N)
        # Space complexity O(K)

        for i in range(len(S)):# O(N)
            char_dict[S[i]] += 1
            if i >= K - 1:# O(1)
                if len(char_dict) == K: res += 1
                char_dict[S[i + 1 - K]] -= 1
                if char_dict[S[i + 1 - K]] == 0: del char_dict[S[i + 1 - K]] # O(1)
        return res
```