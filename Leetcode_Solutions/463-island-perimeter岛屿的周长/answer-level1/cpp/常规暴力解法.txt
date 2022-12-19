```c++ []
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int perimeter = 0;
		for (size_t i = 0; i < grid.size(); i++) {
			size_t j = 0;
			for (; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					perimeter += 4;
                    //需要注意是否在边界
					if (j > 0 && grid[i][j - 1] == 1) {	//如果左边为陆地
						perimeter--;
					}
					if (i > 0 && grid[i - 1][j] == 1) {	//如果上边为陆地
						perimeter--;
					}
					if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) {	//如果右边为陆地
						perimeter--;
					}
					if (i < grid.size() - 1 && grid[i + 1][j] == 1) {	//如果下边为陆地
						perimeter--;
					}
				}
			}
		}
		return perimeter;
	}
};
```
