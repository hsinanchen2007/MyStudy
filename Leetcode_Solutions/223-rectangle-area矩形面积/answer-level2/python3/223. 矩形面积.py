
```python []
class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        s = (G - E) * (H - F) + (C - A) * (D - B)
        if A >= G or B >= H or C <= E or D <= F:
            return s
        (_, a, b, _), (_, c, d, _) = sorted((A, C, E, G)), sorted((B, D, F, H))
        return s - (b - a) * (d - c)
```