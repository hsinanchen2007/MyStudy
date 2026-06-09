直接模拟该题即可。从点`(x1, y1)`到点`(x2, y2)`的时间是`max(abs(x1-x2), abs(y1-y2))`。累加计算即可。
1. 如果两点的横坐标或者纵坐标相等，则距离是：`abs(y1-y2) or abs(x1-x2)`
2. 如果两点的横坐标和纵坐标都不相等，则先走对角线到同一横坐标或者同一纵坐标，然后纵走/横走，此时的距离是：`min(abs(x1-x2), abs(y1-y2)) + max(abs(x1-x2), abs(y1-y2)) - min(abs(x1-x2), abs(y1-y2)) = max(abs(x1-x2), abs(y1-y2))`
3. 综上，两点之间最短时间是`max(abs(x1-x2), abs(y1-y2))`
```
class Solution {
public:
	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int nTime = 0;
		for (size_t i = 1; i < points.size(); ++i) {
			int nDiffX = abs(points[i][0] - points[i - 1][0]);
			int nDiffY = abs(points[i][1] - points[i - 1][1]);
			nTime += max(nDiffX, nDiffY);
		}

		return nTime;
	}
};
```
我果真不适合写题解，写文章啊！