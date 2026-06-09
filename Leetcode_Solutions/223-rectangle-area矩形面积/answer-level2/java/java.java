### 解题思路
关键在于判断两个图形有无重叠部分

### 代码

```java
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = Math.abs((C-A) * (D-B));
        int area2 = Math.abs((G - E) * (H - F));
        int area3 = area1 + area2;
        int g = Math.max(A, E);
        int f = Math.min(C, G);
        int ff = Math.max(B, F);
        int gg = Math.min(D, H);
        // 判断两个图形有无重叠
        if (f > g && gg > ff) {
            int dd = Math.abs(g-f);
            int cc = Math.abs(ff-gg);
            return area3 - dd*cc;
        }
        return area3;
    }
}
```