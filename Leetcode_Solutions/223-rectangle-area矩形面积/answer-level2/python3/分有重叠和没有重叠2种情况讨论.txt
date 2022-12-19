```
class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        if A > E:   #1在左，2在右。如果不是，调过来
            return self.computeArea(E,F,G,H,A,B,C,D)    
        a1_left, a1_down, a1_right, a1_up = A, B, C, D
        a2_left, a2_down, a2_right, a2_up = E, F, G, H
        s1 = (a1_up - a1_down) * (a1_right - a1_left)
        s2 = (a2_up - a2_down) * (a2_right - a2_left)
        if (a2_down>=a1_up) or (a2_left>=a1_right) or (a2_up<=a1_down):
            return s1 + s2
        
        overlap_up = min(a1_up, a2_up)
        overlap_down = max(a1_down, a2_down)
        overlap_left = max(a1_left, a2_left)
        overlap_right = min(a1_right, a2_right)
        s_overlap = (overlap_up - overlap_down) * (overlap_right - overlap_left)

        return s1 + s2 - s_overlap    
```
