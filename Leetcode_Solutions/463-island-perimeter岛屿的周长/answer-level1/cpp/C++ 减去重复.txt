一个方块提供4， 两个方块的公共边不算在周长内
所以只要有一公共边， 就少了2；
只需要计算左上两个方向的公共边。
```
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
		
		int m = grid.size();
		
		if(m <= 0)
		{
			return 0;
		}
		
		int n = grid[0].size();
		
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(grid[i][j] == 1)
				{
					ret += 4;
					
					if(i > 0 && grid[i - 1][j] == 1)
					{
						ret -= 2;
					}
					
					if(j > 0 && grid[i][j - 1] == 1)
					{
						ret -= 2;
					}
				}
			}
		}
		
		return ret;
    }

private:
	int ret = 0;
};
```
