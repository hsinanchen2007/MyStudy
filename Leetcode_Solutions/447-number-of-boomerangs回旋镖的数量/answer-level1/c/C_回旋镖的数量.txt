### 解题思路
思路一 ： 从点集中选取两点ij，组成一个线段，再从点集中找出落在线段的垂直平分线上的点k，统计k的个数（O(n^3)会超时）
思路二 ： 从点集中选取一点i，计算所有其他点j到这个点的距离，统计j->i距离相等的点数n。则对于点i有“回旋镖”n\*(n-1)个。（有n个点，每次取两个放在i的左右，根据排列组合公式，有n!/(n-2)!种排列方法）（统计距离相同的点数的时候，需要Hash等数据结构，对C来说不友好）
### 代码

```c
思路一：（超时）
int distance_2(int X1, int Y1, int X2, int Y2)
{
	int x = X1 > X2 ? X1 - X2 : X2 - X1;
	int y = Y1 > Y2 ? Y1 - Y2 : Y2 - Y1;
	return x * x + y * y;
}
int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize) {
	int result = 0;
	for (int i = 0; i < pointsSize; ++i)
		for (int j = 0; j < pointsSize; ++j)
			for (int k = 0; k < pointsSize; ++k)
				if (i != j && distance_2(points[i][0], points[i][1], points[k][0], points[k][1])
					== distance_2(points[j][0], points[j][1], points[k][0], points[k][1]))
					++result;
	return result;
}

思路二：可以通过。参考
作者：shugangwang
链接：https://leetcode-cn.com/problems/number-of-boomerangs/solution/cyu-yan-shi-xian-by-shugangwang-8/

```