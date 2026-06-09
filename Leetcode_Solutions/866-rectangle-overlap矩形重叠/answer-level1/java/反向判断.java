### 解题思路
本来按照正常考虑相交情景，发现情景过多不好判断，反过来判断不相交场景则简单很多，无非一个在一个的上下左右四个位置，上下左右由于都是相对的，所以其实只有两种场景需要考虑，如下

### 代码

```java
class Solution {
//	private boolean isPointInRectangle(int x, int y, int[] rec2) {
//		if(x > rec2[0] && x < rec2[2] && y > rec2[1] && y  <rec2[3]) {
//			return true;
//		}
//		return false;
//	}
//	
//	private boolean isRectangleInRectangle(int[] rec1, int[] rec2) {
//		if(rec1[0] >= rec2[0] && rec1[1] >= rec2[1]&& rec1[2] <= rec2[2]&& rec1[3] <= rec2[3]) {
//			return true;
//		}
//		return false;
//	}
	private boolean isLeft(int x, int[] rec2) {
		if(x<=rec2[0])
		{
			return true;
		}
		return false;
	}
	
	private boolean isDown(int y, int[] rec2) {
		if(y<=rec2[1])
		{
			return true;
		}
		return false;
	}
	
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
//        if(isPointInRectangle(rec1[0],rec1[1],rec2) ||  isPointInRectangle(rec1[2],rec1[3],rec2)) {
//        	return true;
//        }
//        else if (isRectangleInRectangle(rec1,rec2) || isRectangleInRectangle(rec2,rec1)) {
//        	return true;
//        }
    	if(isLeft(rec1[2],rec2) || isLeft(rec2[2],rec1) || isDown(rec1[3], rec2) || isDown(rec2[3], rec1)){
        return false;}
    	else return true;
    }
}
```