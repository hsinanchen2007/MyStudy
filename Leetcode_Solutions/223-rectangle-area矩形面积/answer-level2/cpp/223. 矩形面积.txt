### 解题思路
重点是矩形重叠部分面积计算。从`836. 矩形重叠`得到的思路：
- 对于x坐标，若A,E中的较大值`x1=max(A,E)`比C,G中的较小值`x2=min(C,G)`还小，那么两矩形在x轴的投影有重叠，重叠的长度为`x2-x1`。
- 对于y坐标，若B,F中的较大值`y1=max(B,F)`比D,H中的较小值`y2=min(D,H)`还小，那么两矩形在y轴的投影有重叠，重叠的长度为`y2-y1`。
- 若x,y坐标均有重叠，那么代表两矩形有重叠，重叠部分面积为x轴重叠长度与y轴重叠长度的乘积`(x2-x1)*(y2-y1)`
计算两个矩形的面积`area1`和`area2`
- 若有重叠，总面积为`area1-(x2-x1)*(y2-y1)+area2`
    - 注意这里减重叠面积放在第二个是因为`area1+area2-(x2-x1)*(y2-y1)`可能会在`area1+area2`阶段超出int的范围导致报错，比如两个完全重叠的矩形面积`area>int/2`（重叠面积也为`area`），总面积为`area`，但是计算过程中会溢出，将重叠部分放在表达式第二个则可以避免这种情况。
- 若无重叠，总面积为`area1+area2`

### 代码

```cpp
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x1 = max(A,E),x2 = min(C,G);
        int y1 = max(B,F),y2 = min(D,H);
        int area1 = (C-A)*(D-B);
        int area2 = (G-E)*(H-F);
        if(x1<x2&&y1<y2)
            return area1-(x2-x1)*(y2-y1)+area2;
        else
            return area1+area2;
    }
};
```