# 200. 岛屿数量
**思路：**
遍历所有的元素，如果该元素为'1'，进入深度优先遍历循环，将所有于该节点相连的'1'改为0，岛屿数量+1，然后继续上述遍历。
**代码实现：**
```
class Solution {
public:
	void recursion( int row, int col, vector<vector<char>>& grid ) {
		if( row < 0
		 || row > grid.size() - 1 
		 || col < 0
		 || col > grid[0].size() - 1
		 || grid[row][col] != '1' ) {
			return;
		}
		
		grid[row][col] = '0';
		
		recursion(row+1,col,grid);
		recursion(row-1,col,grid);
		recursion(row,col+1,grid);
		recursion(row,col-1,grid);
	}
	
    int numIslands(vector<vector<char>>& grid) {
		int sum = 0;
        for ( int i = 0; i < grid.size(); i++ ) {
			for ( int j = 0; j < grid[0].size(); j++ ) {
				if ( grid[i][j] == '1' ) {
					recursion(i,j,grid);
					++sum;
				}
			}
		}
		return sum;
    }
};
```
