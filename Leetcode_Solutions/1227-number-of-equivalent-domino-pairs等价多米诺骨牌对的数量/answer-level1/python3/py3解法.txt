```
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        m = {}
        for a, b in dominoes:
            if a > b:
                a, b = b, a

            if (a, b) not in m:
                m[(a, b)] = 1
            else:
                m[(a, b)] += 1

        sum = 0
        for n in m.values():
            sum += (n * (n-1)) // 2
        return sum
```
