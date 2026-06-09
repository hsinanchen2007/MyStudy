```
class Solution:
    def longestWord(self, words: List[str]) -> str:
        dict = [[] for _ in range(31)]
        for word in words:
            dict[len(word)].append(word)

        longestword = set(dict[1])
        for i in range(2, 31):
            tmp = [w for w in dict[i] if w[:-1] in longestword]
            if not tmp:
                break
            longestword = tmp

        return sorted(longestword)[0]
```
