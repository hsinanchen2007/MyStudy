可以算的节约一点，只算对所求杯子里有贡献的。

```python
import collections


class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        if query_row == query_glass == 0:
            return int(poured > 0)
        champange_through = collections.defaultdict(int)
        champange_through[(0, 0)], i, j, abundant = poured, 0, 0, True
        while i + j <= query_row + query_glass:
            if j < min(i, query_glass):
                j += 1
            elif i < query_row:
                if not abundant:
                    break
                abundant = False
                i += 1
                j = max(0, i - query_row + query_glass)
            else:
                break
            champange_through[(i, j)] = 0.5 * max(0, champange_through[
                (i - 1, j - 1)] - 1) + 0.5 * max(0, champange_through[(i - 1, j)] - 1)
            abundant |= champange_through[(i, j)] > 1
        return min(1, champange_through[(query_row, query_glass)])
```

也可以奔放一些，上面杯子全算，貌似这样更快些。

```python
class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        if query_row == query_glass == 0:
            return int(poured > 0)
        cur, row = [poured], 0
        while row < query_row:
            row += 1
            poured_down = [0] + [0.5 * (i - 1) if i > 1 else 0 for i in cur] + [0]
            cur = [poured_down[i] + poured_down[i + 1] for i in range(row + 1)]
            if row == query_row:
                return min(1, cur[query_glass])
            if all(i <= 1 for i in cur):
                break
        return 0
```