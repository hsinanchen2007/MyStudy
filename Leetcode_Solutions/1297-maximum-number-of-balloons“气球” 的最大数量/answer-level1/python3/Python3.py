```
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        word = 'balloon'
        counts = [0, 0, 0, 0, 0]
        c_array = ['b', 'a', 'l', 'o', 'n']
        for c in text:
            if c in word:
                counts[c_array.index(c)] += 1
        counts[2] = counts[2] // 2
        counts[3] = counts[3] // 2
        return min(counts)
```
