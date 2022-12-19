
```python []

class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        a = (C-A)*(D-B)
        b = (G-E)*(H-F)
        x = max(0,min(C,G)-max(A,E))
        y = max(0,min(D,H)-max(B,F))
        area = a+b-x*y
        return area
```



