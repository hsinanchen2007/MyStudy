```
from collections import defaultdict
class Solution:
    def findLonelyPixel(self, picture: List[List[str]]) -> int:
        line = defaultdict(int)
        row = defaultdict(int)
        ans = []
        for i in range(picture.__len__()):
            for j in range(picture[0].__len__()):
                if picture[i][j] == "B":
                    ans.append([i,j])
                    line[i] += 1
                    row[j] += 1
        count = 0
        for i, j in ans:
            if line[i] == 1 and row[j] ==1:
                count += 1
        return count
```
