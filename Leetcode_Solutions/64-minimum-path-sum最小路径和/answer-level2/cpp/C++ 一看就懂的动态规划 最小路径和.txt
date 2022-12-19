### 解题思路
本题可以和不同路径I,不同路径II一起打包做。
[https://leetcode-cn.com/problems/unique-paths/solution/c-shuang-100-shi-shang-zui-quan-3fa-dong-tai-gui-h/]()
唯一需要注意的是：int可能会越界，所以要换用double 或者是long long。
**TIPS：**
 1. a数组记录的是从起点grid[0][0]到该点的最小路径之和。
 2. 本方法是另开建一个数组记录最小路径和，也可以在原数组grid上修改，以降低复杂度。（但出于传入的是引入，为不修改原变量，并没有这样做）。

### 代码

```cpp
class Solution {
public:
int minPathSum(vector<vector<int>>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	double **a = new double*[n];//a数组记录从起点到该点的最小路径和
	for (int i = 0; i < n; i++)
		a[i] = new double[m]();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 && j == 0)
				a[i][j] = grid[0][0];
			else if (i == 0)
				a[0][j] = a[0][j - 1] + grid[i][j];
			else if (j == 0)
				a[i][0] = a[i - 1][0] + grid[i][j];
			else
				a[i][j] = min(a[i - 1][j], a[i][j - 1]) + grid[i][j];
		}
	}
	double temp = a[n - 1][m - 1];
	for (int i = 0; i < n; i++)
		delete[]a[i];
	delete[]a;
	return  temp;//动态规划
}
};
```