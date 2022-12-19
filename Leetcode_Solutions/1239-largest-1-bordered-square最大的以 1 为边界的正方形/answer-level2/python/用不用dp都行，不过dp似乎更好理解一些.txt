### 不用DP

```python
class Solution(object):
    def largest1BorderedSquare(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def is1Bordered(i, j, width):
            """
            return 0 if it is there no border that contains width 1
            return 1 if top and left borders have width which is 1
            return 2 if all borders are width which is 1
            """
            for x in range(i, i + width):
                if grid[x][j] != 1:
                    return 0
            for y in range(j, j + width):
                if grid[i][y] != 1:
                    return 0
            for x in range(i, i + width):
                if grid[x][j + width - 1] != 1:
                    return 1
            for y in range(j, j + width):
                if grid[i + width - 1][y] != 1:
                    return 1
            return 2

        m, n = len(grid), len(grid[0])
        i, j = 0, 0
        max_width = 0
        while i < m - max_width and j < n - max_width:
            possible_len = max_width + 1
            result = is1Bordered(i, j, possible_len)
            if result == 2:
                max_width = possible_len
            while result > 0 and i < m - possible_len and j < n - possible_len:
                possible_len += 1
                result = is1Bordered(i, j, possible_len)
                if result == 2:
                    max_width = possible_len
            j += 1
            if j >= n - max_width:
                i += 1
                j = 0

        return max_width ** 2

```

### 用DP
```
class Solution(object):
    def largest1BorderedSquare(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        dp_left = [[0] * (n + 1) for _ in range(m + 1)]
        dp_up = [[0] * (n + 1) for _ in range(m + 1)]
        max_width = 0
        for i in range(1,  m + 1):
            for j in range(1, n + 1):
                if grid[i - 1][j - 1] == 1:
                    dp_left[i][j] = dp_left[i][j - 1] + 1
                    dp_up[i][j] = dp_up[i - 1][j] + 1
                    d = min(dp_left[i][j], dp_up[i][j])
                    while d > max_width and i - d >= 0 and j - d >= 0:
                        if dp_up[i][j - d + 1] >= d and dp_left[i - d + 1][j] >= d:
                            max_width = d
                            break
                        d -= 1
        return max_width ** 2 
```
