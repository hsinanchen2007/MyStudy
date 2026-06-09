```python
class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        # bottom-left corner
        # top-right corner

        # X overlap
        # y overlap
        def get_interval(x, y):
            if x[0] > y[0]:
                x, y = y, x
            if x[1] < y[0] : return 0
            else: return min(y[1], x[1]) - max(x[0], y[0])
        def get_area(x, y):
            return (x[1] - x[0]) * (y[1] - y[0])

        AC = [A, C]
        BD = [B, D]
        EG = [E, G]
        FH = [F, H]
        interval_x = get_interval(AC, EG)
        interval_y = get_interval(BD, FH)
        area1 = get_area(AC, BD)
        area2 = get_area(EG, FH)
        interaction = interval_x * interval_y
        return area1 + area2 - interaction
```