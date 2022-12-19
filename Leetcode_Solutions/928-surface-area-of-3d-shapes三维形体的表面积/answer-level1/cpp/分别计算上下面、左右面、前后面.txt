分别计算上下面、左右面、前后面。
上下面好算，看看有几个格子里有方块，上面和下面面积就各是多少。
左右面和前后面不能只取每行每列的最大值求和来算，因为中间可能被围出其他的面积。
所以换个思路，统计所有表面积，再减去两个格子表面重合部分的面积。
明明这个思路不错，可是执行时间和内存占用都只超过了大概5%的人，可悲。

**代码**
```C++ []
class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
		if (grid.size() == 0)
			return 0;
		if (grid[0].size() == 0)
			return 0;

		int up = 0;	//上下面面积
		for (auto v : grid) {
			for (auto data : v) {
				if (data)
					up++;
			}
		}
		up *= 2;
		int left = 0;	//左右面面积
		for (auto v : grid) {
			left += accumulate(v.begin(), v.end(), 0);
			for (int i = 0; i < (int)v.size() - 1; i++)
				left -= min(v[i], v[i + 1]);
		}
		left *= 2;
		int front = 0;	//前后面面积
		for (auto v : grid)
			front += accumulate(v.begin(), v.end(), 0);
		for (int j = 0; j < grid[0].size(); j++) {
			for (int i = 0; i < (int)grid.size() - 1; i++) {
				front -= min(grid[i][j], grid[i + 1][j]);
			}
		}
		front *= 2;
		return up + left + front;
	}
};
```
