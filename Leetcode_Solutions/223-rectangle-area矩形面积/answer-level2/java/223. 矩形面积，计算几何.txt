### 解题思路
1. 计算重叠部分的矩形面积。
    - 先计算两个矩形在`x轴`投影的重叠长度 `xOverLapLine`
    - 再计算两个矩形在`y轴`投影的重叠长度 `yOverLapLine`
    - 合并前两部的结果得到重叠矩形面积 `xOverLapLive * yOverLapLine`
2. 两个矩形面积 - 重叠部分面积 得到结果。

### 代码2（更优雅的重叠判断）

```java
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int xOverLapLine = overLapLine(A, C, E, G);
        int yOverLapLine = overLapLine(B, D, F, H);
        // System.out.println(xLine + ", " + yLine);
        int overLapArea = xOverLapLine * yOverLapLine;
        int totalArea = (C-A)*(D-B) - overLapArea + (G-E)*(H-F);
        return totalArea;
    }

    // 计算重叠线段
    private int overLapLine(int x1, int x2, int x3, int x4) {
        int maxLeft = Math.max(x1, x3);
        int minRight = Math.min(x2, x4);
        if (minRight < maxLeft) return 0;
        return maxLeft - minRight;
    }
}
```

### 代码1（原始的丑的重叠判断）
```java
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int xOverLapLine = overLapLine(A, C, E, G);
        int yOverLapLine = overLapLine(B, D, F, H);
        // System.out.println(xLine + ", " + yLine);
        int overLapArea = xOverLapLine * yOverLapLine;
        int totalArea = (C-A)*(D-B) + (G-E)*(H-F);
        return totalArea - overLapArea;
    }

    private int overLapLine(int x1, int x2, int x3, int x4) {
        if (x1 > x3) return overLapLine(x3, x4, x1, x2);
        if (x2 <= x3) return 0;
        return Math.min(x2, x4) - x3;
    }
}
```