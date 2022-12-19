会初中解二元一次方程的，就可以理解这道题
这道题，我比较担心的是，double计算带来的误差。
判断几个点，两条线段是否有竖线
两条线是否平行
然后再找交点，判断交点是否在线段上
```
class Solution {
    //时刻警惕，double的计算有误差，如果算出结果是1.000000001,而实际答案是1,可能会因为超出范围而选择舍弃。
    //解决办法，边界的先判断是否在直线上
    public double[] intersection(int[] start1, int[] end1, int[] start2, int[] end2) {
        double[] ans = new double[2];
        //如果line1是竖着的
        if (start1[0] == end1[0]) {
            //如果line2也是竖着的
            if (start2[0] == end2[0]) {
                //如果不同
                if (start1[0] != start2[0]) {
                    return new double[0];
                } else {
                    //是否相交
                    int x1 = Math.min(start1[1], end1[1]);
                    int x2 = Math.max(start1[1], end1[1]);
                    int y1 = Math.min(start2[1], end2[1]);
                    int y2 = Math.max(start2[1], end2[1]);
                    if (x1 > y2 || y1 > x2) {
                        //不想交
                        return new double[0];
                    } else {
                        return new double[]{start1[0], Math.max(x1, y1)};
                    }
                }
            }
            return getByOneShuzhe(start2, end2, start1[0], Math.min(start1[1], end1[1]), Math.max(start1[1], end1[1]));
        }
        //如果line2是竖着的
        if (start2[0] == end2[0]) {
            return getByOneShuzhe(start1, end1, start2[0], Math.min(start2[1], end2[1]), Math.max(start2[1], end2[1]));
        }
        //两条线都是斜着的
        //两条直线方程
        //(end[1]-start[1])*x-(end[0]-start[0])*y = end[1]*start[0]-end[0]*start[1];
        //判断斜率是否相同
        //(end[1]-start[1])/(end[0]-start[0])
        if ((long) (end1[1] - start1[1]) * (long) (end2[0] - start2[0])
                == (long) (end2[1] - start2[1]) * (long) (end1[0] - start1[0])) {
            //斜率相同判断是否过同一点
            //(end[1]*start[0]-end[0]*start[1])/(end[0]-start[0])
            if ((long) (end1[1] * start1[0] - end1[0] * start1[1]) * (long) (end2[0] - start2[0])
                    == (long) (end2[1] * start2[0] - end2[0] * start2[1]) * (long) (end1[0] - start1[0])) {
                //如果过同一点，查询这个点
                int x1 = Math.min(start1[0], end1[0]);
                int x2 = Math.max(start1[0], end1[0]);
                int y1 = Math.min(start2[0], end2[0]);
                int y2 = Math.max(start2[0], end2[0]);
                if (x1 > y2 || x2 < y1) {
                    return new double[0];
                }
                int x = Math.max(x1, y1);
                if (x == start1[0]) {
                    return new double[]{start1[0], start1[1]};
                } else if (x == end1[0]) {
                    return new double[]{end1[0], end1[1]};
                } else if (x == start2[0]) {
                    return new double[]{start2[0], start2[1]};
                } else {
                    return new double[]{end2[0], end2[1]};
                }
            } else {
                //平行线不会相交
                return new double[0];
            }
        }
        //当两条线不平行时
        int[] left1 = null;
        int[] right1 = null;
        if (start1[0] < end1[0]) {
            left1 = start1;
            right1 = end1;
        } else {
            right1 = start1;
            left1 = end1;
        }
        int[] left2 = null;
        int[] right2 = null;
        if (start2[0] < end2[0]) {
            left2 = start2;
            right2 = end2;
        } else {
            right2 = start2;
            left2 = end2;
        }
        if (left1[0] > right2[0] || left2[0] > right1[0]) {
            return new double[0];
        }
        if (check(left1, right1, left2)) {
            return new double[]{left2[0], left2[1]};
        }
        if (check(left1, right1, right2)) {
            return new double[]{right2[0], right2[1]};
        }
        if (check(left2, right2, left1)) {
            return new double[]{left1[0], left1[1]};
        }
        if (check(left2, right2, right1)) {
            return new double[]{right1[0], right1[1]};
        }
        //计算交点
        //(end1[1]-start1[1])*x-(end1[0]-start1[0])*y = end1[1]*start1[0]-end1[0]*start1[1];
        //(end2[1]-start2[1])*x-(end2[0]-start2[0])*y = end2[1]*start2[0]-end2[0]*start2[1];
        //第一个等式*(end2[0]-start2[0])
        //第二个等式*(end1[0]-start1[0])
        //再做差
        //((end1[1]-start1[1])*(end2[0]-start2[0]))-((end2[1]-start2[1])*(end1[0]-start1[0]))*x=
        //(end1[1]*start1[0]-end1[0]*start1[1])*(end2[0]-start2[0]) - (end2[1]*start2[0]-end2[0]*start2[1])*(end1[0]-start1[0])
        double x = ((1.0 * end1[1] * start1[0] - 1.0 * end1[0] * start1[1]) * (end2[0] - start2[0]) - (1.0 * end2[1] * start2[0] - 1.0 * end2[0] * start2[1]) * (end1[0] - start1[0])) /
                ((1.0 * (end1[1] - start1[1]) * (end2[0] - start2[0])) - (1.0 * (end2[1] - start2[1]) * (end1[0] - start1[0])));
        if (x < left1[0] || x > right1[0] || x < left2[0] || x > right2[0]) {
            return new double[0];
        }
        double y = (x * (end1[1] - start1[1]) - (1.0 * end1[1] * start1[0] - 1.0 * end1[0] * start1[1])) / (end1[0] - start1[0]);
        return new double[]{x, y};
    }

    private boolean check(int[] left, int[] right, int[] node) {
        if (node[0] < left[0] || node[0] > right[0]) {
            return false;
        }
        //(right[1]-left[1])/(right[0]-left[0]) = (node[1]-left[1])/(node[0]-left[0])
        return (long) (right[1] - left[1]) * (long) (node[0] - left[0]) == (long) (node[1] - left[1]) * (long) (right[0] - left[0]);
    }

    //一条竖着的，加一条斜着的
    private double[] getByOneShuzhe(int[] start2, int[] end2, int y, int min, int max) {
        int[] left = null;
        int[] right = null;
        if (start2[0] < end2[0]) {
            left = start2;
            right = end2;
        } else {
            right = start2;
            left = end2;
        }
        if (left[0] > y || right[0] < y) {
            return new double[0];
        }
        //因为double计算不精确,所以先检查min,和max是否是答案
        if ((long) (y - left[0]) * (long) (right[1] - left[1]) == (long) (min - left[1]) * (long) (right[0] - left[0])) {
            return new double[]{y, min};
        }
        if ((long) (y - left[0]) * (long) (right[1] - left[1]) == (long) (max - left[1]) * (long) (right[0] - left[0])) {
            return new double[]{y, max};
        }
        //(y-left[0])/(right[0]-left[0]) = (h-left[1])/(right[1]-left[1])
        double h = 1.0 * (y - left[0]) * (right[1] - left[1]) / (right[0] - left[0]) + left[1];
        if (h > max || h < min) {
            return new double[0];
        } else {
            return new double[]{y, h};
        }
    }
}


```
