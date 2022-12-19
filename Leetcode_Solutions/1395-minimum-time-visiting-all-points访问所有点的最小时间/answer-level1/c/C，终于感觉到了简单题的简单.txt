![1.png](https://pic.leetcode-cn.com/64dfb878cce690c1a35f29cce6c1c1eac725b9cf44894ddece4821add683b54e-1.png)

### 解题思路
每次的时间是坐标差的绝对值的最大值

### 代码

```c
int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
	if (pointsSize == 1)
		return 0;
	int max = 0, a, b;
	for (int i = 1; i < pointsSize; i++){
		a = abs(points[i][0] - points[i - 1][0]);
		b = abs(points[i][1] - points[i - 1][1]);
		max += a>b ? a : b;
	}
	return max;
}
```