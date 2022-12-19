### 解题思路
先确定矩行哪个在左面，
		下面是不重叠的几种请况
		1.left矩形的右边是否  <= right矩形的左边
		2.left矩形的下边是否  >= right矩形的上边
		2.left矩形的上边是否  <= right矩形的下边

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int[] left=rec1;
		int[] right=rec2;
		if(rec1[0]>rec2[0]) {
			left=rec2;
			right=rec1;
		}
		if(left[2]<=right[0]||left[1]>=right[3]||left[3]<=right[1]) {
			return false;
		}
		return true;
    }
}
```