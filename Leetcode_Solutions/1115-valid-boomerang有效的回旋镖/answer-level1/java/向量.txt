首先，设三个点分别为A：(xa,ya),B：(xb,yb),C：(xc,yc)，分别按顺序对应数组中的三个点。
    要求A、B、C三点不在同一条直线上，需要 向量AB与向量AC不共线。
向量AB = (x1,y1)，其中 x1 = xb - xa，y1 = yb - ya
向量BC = (x2,y2)，其中 x2 = xc - xb, y2 = yc - yb

若AB、BC共线，则：y1/x1 = y2/x2。为了防止出现 x1 或者 x2 等于 0 的情况，将等式进行处理，
变为乘法的形式，即：y1x2 = y2x1。 满足该等式即返回“false”，不满足则返回“true”。

代码如下：
```
class Solution {
    public boolean isBoomerang(int[][] points) {
        int x1 = points[1][0] - points[0][0],x2 = points[2][0] - points[0][0];
		int y1 = points[1][1] - points[0][1],y2 = points[2][1] - points[0][1];
		if(y1 * x2 == y2 * x1)
			return false;
	    return true;
    }
}
```