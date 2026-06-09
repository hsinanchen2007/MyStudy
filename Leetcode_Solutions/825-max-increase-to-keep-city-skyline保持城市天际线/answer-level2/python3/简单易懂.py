```
class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        lst1 = [max(i) for i in grid]
        lst2 = [max(j) for j in zip(*grid)]
        count = 0
        for i in range(len(lst1)):
            for j in range(len(lst2)):
                if lst1[i]<lst2[j]:
                    count += lst1[i]-grid[i][j]
                else:
                    count += lst2[j]-grid[i][j]
        return count
```
