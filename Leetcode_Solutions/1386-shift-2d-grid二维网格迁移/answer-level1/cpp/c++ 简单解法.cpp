
先把需求进行整理,结果如下：
grid[i][j] = grid[i][j-1];
grid[i][0] = grid[i-1][m-1];
grid[0][0] = grid[n-1][m-1];
仔细分析看出以上操作，实质就是把依次把位置往后面移动了K位
第一行需求，用一个for循环解决，第二行和第三行可以合并解决
```
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();	
        for (int a = 0; a < k; a++) 
	    {
	    	vector<vector<int>> result = grid;
            for (int i = 0; i < n; i++) 
	    	{              
                for (int j = 1; j < m; j++) 
	    		{
                    grid[i][j] = result[i][j - 1];
                }
                grid[i][0] = i >= 1 ? result[i - 1][m - 1] : result[n - 1][m - 1];
            }
        }	
        return grid;
    }
};
```
