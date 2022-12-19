### 解题思路
参考了[矩形重叠题目中，官方的解题方案2](https://leetcode-cn.com/problems/rectangle-overlap/solution/ju-xing-zhong-die-by-leetcode-solution/)，感谢

思路

如果两个矩形重叠，那么它们重叠的区域一定也是一个矩形，那么这代表了两个矩形与 X轴平行的边（水平边）投影到X轴上时会有交集，与Y轴平行的边（竖直边）投影到Y轴上时也会有交集。因此，我们可以将问题看作一维线段是否有交集的问题。

算法

矩形 rec1 和 rec2 的水平边投影到 X轴上的线段分别为 (A, C) 和 (E, G)。根据数学知识我们可以知道，
- 当 min(G, C) > max(A, E) 时，这两条线段有交集。对于矩形 rec1 和 rec2 的竖直边投影到 Y 轴上的线段，
- 同理可以得到，当 min(H, D) > max(F, B) 时，这两条线段有交集。

本题中，要计算重叠后的总面积，所以还要考虑矩形不重叠的情况，因此稍作改变，将上述七年概况改为减法，只要不满足上述重叠情况，必然有小于0的情况出现，此时只需要赋值为0即可，因为0乘以任何数还是0，这样就不会影响面积的计算；
如果有重叠，则只需要减去重叠部分的面积即可。


### 代码

```python3
class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:

        val_x = min(C, G) - max(A, E)
        val_y = min(D, H) - max(B, F)

        return (C-A)*(D-B) + (G-E)*(H-F) - max(val_x,0)*max(val_y,0)
```