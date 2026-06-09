问题：

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。

 


分析：

根据两点确定一条直线原理，我们可以选取两个点确定一条直线，再看看其他的点有多少位于这条直线上，这题主要思路就这么简单，之所以是个困难题，因为有很多特殊情况要考虑

第一，斜率的计算，如果用除法计算斜率，会有斜率为无穷大的问题，另外除法的结果是浮点数，可能会有不精确的问题，所以我们使用乘法来进行斜率的比较，当然乘法也要注意，int的乘法结果可能会超出上限，要用long来保存乘法结果

第二，重复点的问题，如果一开始选取用来确定一条直线的两个点是重复点就会造成问题，应该跳过这种情况

 


代码：

```
/**
 * 直线上最多的点数
 * Max Points on a Line
 *
 * @author DongWei
 * @date 2019/5/22
 */
class Solution {
    public int maxPoints(int[][] points) {
        // 如果总坐标点少于 3 个，直接返回答案
        int n = points.length;
        if (points.length <= 2) return n;

        // 搜索直线上最多的点数
        int max = 0;
        for (int i = 0; i < n; i ++) {
            // same 表示有多少个和 i 一样的点
            int same = 1;
            for (int j = i + 1; j < n; j ++) {
                // cnt 表示除了 i 坐标点外，有多少个点在 i、j 坐标点构成的直线上
                int cnt = 0;
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    // i、j 是重复点，计数
                    same ++;
                } else {
                    // i、j 不是重复点，检查其他点是否在这条直线上，j 坐标点也在这条直线上，所以 cnt ++
                    cnt ++;
                    long xDiff = (long)(points[i][0] - points[j][0]);
                    long yDiff = (long)(points[i][1] - points[j][1]);
                    for (int k = j + 1; k < n; k ++) {
                        if (xDiff * (points[i][1] - points[k][1]) == yDiff * (points[i][0] - points[k][0])) {
                            cnt ++;
                        }
                    }
                }
                // 最大值比较
                max = Math.max(max, cnt + same);
            }
        }
        return max;
    }
}
```

这个代码跑起来在20ms以内，最快能到10ms，每次结果都不一样
