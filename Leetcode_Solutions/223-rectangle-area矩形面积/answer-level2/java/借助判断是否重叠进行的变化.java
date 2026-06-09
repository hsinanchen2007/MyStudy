```
class Solution:
    def isRectangleOverlap(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> bool:#转为x与y轴上的线段判断
        return (min(C, G) > max(A, E) and min(D, H) > max(B, F))
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        s1 = (D - B) * (C - A)
        s2 = (H - F) * (G - E)
        if self.isRectangleOverlap(A, B, C, D, E, F, G, H):
            sum = s1 + s2 - (min(C, G) - max(A, E)) * (min(D, H) - max(B, F))
        else:
            sum = s1 + s2
        return sum
```
```
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int l1 = Math.min(G, C);
        int l2 = Math.max(A, E);
        int r1 = Math.min(D, H);
        int r2 = Math.max(B, F);
        
        int s1 = (D-B) * (C-A);
        int s2 = (H-F) * (G-E);
        int sum;

        if(l1 > l2 && r1 > r2) {
            sum = s1 + s2 - (l1 - l2) * (r1 - r2);
        }
        else {
            sum = s1 + s2;
        }
        return sum;
    }
}
```
