### 解题思路
此处撰写解题思路
分两步：
1. 贯穿的情况：比较点即可
2. 第二种情况：有一个点在另一个长方形中，这种情况要注意可能有溢出的情况
### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
		// 有交叠，说明总有一个点在另一个长方形内
		int[] p1 = {rec1[0], rec1[3]};		int[] p2 = {rec1[2], rec1[3]};
		int[] p3 = {rec1[0], rec1[1]};		int[] p4 = {rec1[2], rec1[1]};
		// 有交叠，说明总有一个点在另一个长方形内
		int[] point1 = {rec2[0], rec2[3]};		int[] point2 = {rec2[2], rec2[3]};
		int[] point3 = {rec2[0], rec2[1]};		int[] point4 = {rec2[2], rec2[1]};
		
		if (rec1[0]>=rec2[0]&&rec1[2]<=rec2[2]&&rec1[1]<=rec2[1]&&rec1[3]>=rec2[3]) return true;
		if (rec2[0]>=rec1[0]&&rec2[2]<=rec1[2]&&rec2[1]<=rec1[1]&&rec2[3]>=rec1[3]) return true;
		
		boolean res1 = isInRectangle(rec1, point1) || this.isInRectangle(rec1, point2) || this.isInRectangle(rec1, point3) || this.isInRectangle(rec1, point4);
		boolean res2 = isInRectangle(rec2, p1) || this.isInRectangle(rec2, p2) || this.isInRectangle(rec2, p3) || this.isInRectangle(rec2, p4);
		return res1 || res2;
	}
	public boolean isInRectangle(int[] rec, int[] point) {
		// 长方形
		int x1 = rec[0]; int y1 = rec[3];
		int x2 = rec[2]; int y2 = rec[1];
		// 一个点
		int x = point[0]; int y = point[1];
		boolean b1 = this.isInMedian(x1, x2, x);
		boolean b2 = this.isInMedian(y1, y2, y);	
		return b1&&b2;
	}
	public boolean isInMedian(int x1, int x2, int x) {
		if (x==x1 || x==x2) return false;
		boolean b1 = x1-x <0; boolean b2 = x2-x>0;
		if (b1 && b2) return true;
		if (!b1 && !b2) return true;
		return false;
	}
}
```