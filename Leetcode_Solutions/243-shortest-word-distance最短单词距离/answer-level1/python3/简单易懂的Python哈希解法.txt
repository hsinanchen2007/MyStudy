```
class Solution:
    def shortestDistance(self, words: List[str], word1: str, word2: str) -> int:
        d = dict()
        for idx, word in enumerate(words):
            if word not in d:
                d[word] = [idx]
            else:
                d[word].append(idx)
        a_list = d[word1]
        b_list = d[word2]
        res = float('+inf')
        for i in a_list:
            for j in b_list:
                res = min(res, abs(i-j))
        return res
```
