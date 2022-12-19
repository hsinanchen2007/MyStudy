来自@[@lu-cheng-5](/u/lu-cheng-5/)的想法
```
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if not numRows:
            return []

        rows = [[1]]
        while len(rows) < numRows:
            rows.append(
                [l + r for l, r in zip([0] + rows[-1], rows[-1] + [0])]
            )
        return rows
```