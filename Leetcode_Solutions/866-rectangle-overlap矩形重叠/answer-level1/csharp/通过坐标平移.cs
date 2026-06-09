### 解题思路
先把坐标平移,以rec1的左下角坐标为原点，再判断rec2平移后x轴和y轴上的点是否在rec1两轴线内.

### 代码

```csharp
public class Solution {
    public bool IsRectangleOverlap(int[] rec1, int[] rec2) {
            int[] rec3 = new int[4];
            int[] rec4 = new int[4];
            for (int i = 0; i < 4; i++)
            {
                rec3[i] = rec2[i] - rec1[i % 2];
                rec4[i] = rec1[i] - rec1[i % 2];
            }
            bool inX = !(rec3[2] <= 0 || rec3[0] >= rec4[2]);
            bool inY = !(rec3[3] <= 0 || rec3[1] >= rec4[3]);
            return inX && inY;
    }
}
```