```python
class Solution:
    def shortestWordDistance(self, words: List[str], word1: str, word2: str) -> int:
        word1_arr, word2_arr = [], []
        # ordered list => min(abs(a - b)) => two pointers
        # special case: word1 == word2
        # Time complexity: O(max(M, N))
        res = float('inf')
        if word1 == word2:
            cur = None
            for i, word in enumerate(words):
                if word == word1:
                    if cur == None: cur = i
                    else:
                        res = min(res, i - cur)
                        cur = i
            return res

        for i, word in enumerate(words):
            if word == word1: word1_arr.append(i)
            elif word == word2: word2_arr.append(i)
        i, j = 0, 0
        while i < len(word1_arr) and j < len(word2_arr):
            res = min(res, abs(word1_arr[i] - word2_arr[j]))
            if word1_arr[i] < word2_arr[j]:
                i += 1
            else: j += 1
        return res


```