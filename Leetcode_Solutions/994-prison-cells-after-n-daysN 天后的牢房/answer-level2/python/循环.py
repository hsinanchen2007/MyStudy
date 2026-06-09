python3方案，每14轮重复一次。

```
class Solution(object):
    def prisonAfterNDays(self, cells, N):
        """
        :type cells: List[int]
        :type N: int
        :rtype: List[int]
        """
        temp = list()
        N = N % 14 + 14
        for i in range(0, N):
            result = list()
            result.append(0)
            for j in range(1, 7):
                if cells[j - 1] == cells[j + 1]:
                    result.append(1)
                else:
                    result.append(0)
            result.append(0)
            cells = result
        return cells
```
