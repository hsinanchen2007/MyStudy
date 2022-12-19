```
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        m, res = [0] * 26, 0
        for c in chars:
            m[ord(c) - ord('a')] += 1
        for word in words:
            tmp = m[:]
            for c in word:
                index = ord(c) - ord('a')
                tmp[index] -= 1
                if tmp[index] < 0:
                    break
            else:
                res += len(word)
        return res
```
