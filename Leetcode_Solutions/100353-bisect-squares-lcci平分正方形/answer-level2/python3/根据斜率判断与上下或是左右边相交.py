```python
class Solution:
    def cutSquares(self, square1: List[int], square2: List[int]) -> List[float]:
        get_x = lambda y: (y - b) / k
        get_y = lambda x: k * x + b
        
        (x1, y1, l1), (x2, y2, l2) = square1, square2
        c1 = (x1 + l1 / 2, y1 + l1 / 2)
        c2 = (x2 + l2 / 2, y2 + l2 / 2)
        dy, dx = c2[1] - c1[1], c2[0] - c1[0]
        points = []
        if dx == 0:
            points = [(c1[0], y1), (c1[0], y1 + l1), (c1[0], y2), (c1[0], y2 + l2)]
        else:
            k = dy / dx
            b = c1[1] - c1[0] * k
            if -1 <= k <= 1:
                points = [(x1, get_y(x1)), (x1 + l1, get_y(x1 + l1)), 
                          (x2, get_y(x2)), (x2 + l2, get_y(x2 + l2))]
            else:
                points = [(get_x(y1), y1), (get_x(y1 + l1), y1 + l1),
                          (get_x(y2), y2), (get_x(y2 + l2), y2 + l2)]
        points = sorted(points)
        return [*points[0], *points[-1]]
            
```