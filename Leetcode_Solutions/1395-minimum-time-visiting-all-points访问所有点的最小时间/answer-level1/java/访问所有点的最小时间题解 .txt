### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int width = 0;
        int height = 0;
        int result = 0;
        int temp = 0;

        for (int i = 0; i < points.length - 1; i++) {
            width = Math.abs(points[i + 1][0] - points[i][0]);
            height = Math.abs(points[i + 1][1] - points[i][1]);
            temp = Math.min(height , width);
            result = result + temp + Math.abs(height - width);
        }
        return result;
    }
}
```
### 思路
1. 题解：
秒数问题，横向一格，纵向一格都是1秒，斜率为1或-1的对角线也是1秒，那尽可能的横向移动和竖向移动即可。

2. 思路
在坐标系上随意标注两个点，记为a(x1,y1),b(x2,y2)，此时按照专业角度来说会引入斜率，如果斜率大于1或小于-1，则说明y增量大，如果斜率小于1且大于-1，则x增量比较大。
上述说法理解起来比较难，现在说个简单的。
1.首先计算两点之间的横坐标差和纵坐标差得到width和height。
2.其次比较两点之间的横纵坐标差（width和height）得到最小值temp。
3.将横坐标移动一个最小值的距离，得到新点t(x1 + temp,y1)。
4.此时计算新点t与b点之间的距离，现在的新点t与b点只有两种情况，1.在同一横坐标；2.两点之间的斜率为1或者-1，也就是类似于（1，1）（2，2）两点.
5.第一种情况只需要计算纵坐标之差，即（y2-y1），第二种情况，由于两者计算结果一致,即（y2-y1） = （x2 - temp - x1），则用第一种（y2-y1）计算即可。
所以，最后结果是横纵坐标之差的最小值temp加上纵坐标的差值，即可得到从一个点到另一个点的最短时间。
