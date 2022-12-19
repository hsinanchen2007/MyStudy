直接把8种幻方加入set中，然后暴力循环判断每个3*3的格子是否在set中，在的话count+1。
至于哪8种，只要写出一种，然后将该幻方旋转和翻转即可。
```
class Solution {
public:
	int numMagicSquaresInside(vector<vector<int>>& grid) {
		int count = 0;
		vector<vector<int>> huanfang = { \
		{8, 1, 6, 3, 5, 7, 4, 9, 2}, \
		{6, 1, 8, 7, 5, 3, 2, 9, 4}, \
		{6, 7, 2, 1, 5, 9, 8, 3, 4}, \
		{2, 7, 6, 9, 5, 1, 4, 3, 8}, \
		{4, 9, 2, 3, 5, 7, 8, 1, 6}, \
		{2, 9, 4, 7, 5, 3, 6, 1, 8}, \
		{8, 3, 4, 1, 5, 9, 6, 7, 2}, \
		{4, 3, 8, 9, 5, 1, 2, 7, 6}};
		set<vector<int>> s;
		for (int i = 0; i < 8; i++){
			s.insert(huanfang[i]);
		}
		for (int i = 1; i < grid.size() - 1; i++){
			for (int j = 1; j < grid[i].size() - 1; j++){
				vector<int> tmp = { 
					grid[i - 1][j - 1], grid[i - 1][j], grid[i - 1][j + 1],\
					grid[i][j - 1], grid[i][j], grid[i][j + 1],\
					grid[i + 1][j - 1], grid[i + 1][j], grid[i + 1][j + 1] };
				if (s.find(tmp) != s.end())
					count++;
				
			}
		}
		return count;
	}
};

```


