```python
class Solution:
    def findLonelyPixel(self, picture: List[List[str]]) -> int:
        row_flag = [0] * len(picture)
        col_flag = [0] * len(picture[0])
        for i in range(len(picture)):
            for j in range(len(picture[0])):
                if picture[i][j] == 'B':
                    row_flag[i] += 1
                    col_flag[j] += 1
        res = 0
        for i in range(len(picture)):
            for j in range(len(picture[0])):
                if picture[i][j] == 'B' and row_flag[i] == 1 and col_flag[j] == 1:
                    res += 1
        return res
```