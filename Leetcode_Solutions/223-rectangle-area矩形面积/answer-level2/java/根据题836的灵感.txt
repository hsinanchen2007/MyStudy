两个矩形面积之和减去重合的矩形面积,重点是求两个矩形重合的面积
根据836题的题解:如果两个矩形重叠，那么它们重叠的区域一定也是一个矩形，那么这代表了两个矩形与 xx 轴平行的边（水平边）投影到 xx 轴上时会有交集，与 yy 轴平行的边（竖直边）投影到 yy 轴上时也会有交集。因此，我们可以将问题看作一维线段是否有交集的问题。
X轴重叠线段的长度为 Math.min(C,G)-Math.max(A,E),同时和0比较,如果小于0,重叠长度为0,同时防止int溢出,得到X轴的重叠线段长度为
```
int x = (int)Math.max(((long)Math.min(C,G)-(long)Math.max(A,E)),0))
```
同理Y轴的重叠线段长度为
int y = (int)Math.max(((long)Math.min(D,H)-(long)Math.max(B,F)),0))

最后的题解写成一行为
```
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (int) ((C-A)*(D-B)+(G-E)*(H-F)-Math.max(((long)Math.min(C,G)-(long)Math.max(A,E)),0)*Math.max(((long)Math.min(D,H)-(long)Math.max(B,F)),0));
    }
}
```
