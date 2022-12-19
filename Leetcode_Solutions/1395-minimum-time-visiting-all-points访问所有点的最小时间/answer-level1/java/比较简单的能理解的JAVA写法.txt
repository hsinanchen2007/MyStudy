- currPoint为当前所在点
- next为后续即将运动到的点
- 每次比较前后两点间距离，如不同，则进行相对运动（++ 或者 -- 操作）


```
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {

int result = 0;
		int[] currPoint = points[0];
		for (int[] point : points) {
			int currX = currPoint[0], currY = currPoint[1];
			int nextX = point[0], nextY = point[1];
			while (currX != nextX || currY != nextY) {
				if (currX > nextX) {
					currX--;
				}
				if (currX < nextX) {
					currX++;
				}
				if (currY > nextY) {
					currY--;
				}
				if (currY < nextY) {
					currY++;
				}
				result++;
			}
			currPoint = point;
		}
		return result;
    }
}
```
