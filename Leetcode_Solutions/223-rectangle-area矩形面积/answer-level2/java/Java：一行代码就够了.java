Java:返回两个面积的和,减去重叠的面积。当没有重叠时边界的差为非正数，直接换成0就行了。
```
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (D-B)*(C-A)+(H-F)*(G-E) - (int)Math.max((long)Math.min(C, G)-(long)Math.max(A, E),0)
            *(int)Math.max((long)Math.min(D, H)-(long)Math.max(B, F),0);
    }
}
```
