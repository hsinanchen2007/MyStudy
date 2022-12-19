```
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        if len(S) < 2:
            return []
        i = 0
        j = 0
        count = 0
        res = []
        while j < len(S):
            if S[j] == S[i]:
                count += 1
                if j == len(S) - 1 and count >= 3:
                    res.append([i,j])
                j += 1
            else:
                if count >= 3:
                    res.append([i,j-1])
                i = j
                count = 0
        return res

```
