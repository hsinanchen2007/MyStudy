### 解题思路
这次代码是根据N皇后的位运算总结出来的，
N皇后的位运算的核心是选择空位置，
int freeLocation=~(col|lx|rx)&((1<<n)-1);此处为N皇后选择（会包含之前的不可选择位置）
int dir = (left | right | up | down)&((1 << 4) - 1);  此处的选择与N皇后不同之处是他不包含之前的不可选择位置

dir为空位置，每次空位置递归后都会减少1个
pick=dir&(-dir)每次选择最右边那个位置
### 代码

```cpp
class Solution {
public:
	bool isFull(std::vector<std::vector<int>>& grid,int row,int coloumn) {
		bool re = true;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 0) re = false;
			}
		}
		//如果第一步检查通过则进行出口检查
		if (re) {
			re = !re;
			//出口检查（此位置周围是否有出口）
			if (row >= 0 && row < grid.size() && coloumn >= 0 && coloumn < grid[0].size()) {
				if ((coloumn - 1) >= 0 && grid[row][coloumn - 1] == 2)re =true;
				if ((coloumn + 1) < grid[0].size() && grid[row][coloumn + 1] == 2)re = true;
				if ((row - 1) >= 0 && grid[row - 1][coloumn] == 2)re = true;
				if ((row + 1) < grid.size() && grid[row + 1][coloumn] == 2)re = true;
			}
		}
		return re;
	}
	void dfs(int row, int coloumn, std::vector<std::vector<int>>& grid) {
		if (grid[row][coloumn] == 0)grid[row][coloumn] = 3;
		if (isFull(grid,row,coloumn)) {
			result++; grid[row][coloumn] = 0; return;//若达到一种方案则回溯
		}
		//计算可选择的空位置
		if (row >= 0 && row < grid.size() && coloumn >= 0 && coloumn < grid[0].size()) {
			if ((coloumn - 1) >= 0 && grid[row][coloumn - 1] == 0)left = 8;
			else left = 0;
			if ((coloumn + 1) < grid[0].size() && grid[row][coloumn + 1] == 0)right = 4;
			else right = 0;
			if ((row - 1) >= 0 && grid[row - 1][coloumn] == 0)up = 2;
			else up = 0;
			if ((row + 1) < grid.size() && grid[row + 1][coloumn] == 0)down = 1;
			else down = 0;
		}
		int dir = (left | right | up | down)&((1 << 4) - 1);//代表可选择的空位置

		while (dir > 0) {
			int pic = dir & -dir;//选择最右边（位）的位置
		  
			//选择下一步要走的路，修改row与coloumn
			if (pic == 8) {  dfs(row, coloumn-1, grid);	}//代表走左边
			else if (pic == 4) { dfs(row, coloumn +1, grid); }//代表走右边
			else if (pic == 2) { dfs(row-1, coloumn , grid); }//代表走上边
			else { dfs(row+1, coloumn , grid); }//代表走下边
			
			dir = dir&(dir - 1);	//去掉最右边的位置回溯
			
		}
		if (dir == 0) grid[row][coloumn] = 0;//若回溯后的空位置为0则置为空位置

	}
	int uniquePathsIII(std::vector<std::vector<int>>& grid) {
		int row = 0, coloumn = 0;
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1)
				{
					row = i; coloumn = j; goto breakLoop;
				}
			}
	breakLoop:	dfs(row, coloumn,  grid);
		return result;
	}
private:
	int result = 0;
	int left = 0;
	int right = 0;
	int up = 0;
	int down = 0;
};
```