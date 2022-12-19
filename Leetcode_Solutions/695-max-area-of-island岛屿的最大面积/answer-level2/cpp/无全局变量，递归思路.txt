### 解题思路
递归查找，
将遍历过的路径改为0
### 代码

```cpp
class Solution
{
public:
	int maxAreaOfIsland(vector<vector<int>>& grid)
	{
		int nMaxArea = 0;//最大面积
		int nTemp = 0;
		int nSize = grid.size();
		int nLen = grid[0].size();
		for (int i = 0; i < nSize; i++)
		{
			for (int j = 0; j < nLen; j++)
			{
				if (1 == grid[i][j])
				{
					GetArea(grid, i, j, nTemp);
					if (nTemp > nMaxArea)
					{
						nMaxArea = nTemp;
					}
					nTemp = 0;
				}
			}
		}
		return nMaxArea;
	}
	void GetArea(vector<vector<int>>& grid, int nRow, int nCol, int &nArea)
	{
		
		int nSize = grid.size();
		int nLen = grid[0].size();
		if (nRow >= nSize || nCol >= nLen || nRow < 0 || nCol < 0)
		{
			return;
		}
		if (0 == grid[nRow][nCol])
		{
			return;
		}
        nArea++;
        grid[nRow][nCol] = 0;
		if (nRow - 1 >= 0 && grid[nRow - 1][nCol])
        {
	        GetArea(grid, nRow - 1, nCol, nArea);
        }
        if (nCol + 1 < nLen && grid[nRow][nCol + 1])
        {
	        GetArea(grid, nRow, nCol + 1, nArea);
        }
        if (nRow + 1 < nSize && grid[nRow + 1][nCol])
        {
	        GetArea(grid, nRow + 1, nCol, nArea);
        }
        if (nCol - 1 >= 0 && grid[nRow][nCol - 1])
        {
            GetArea(grid, nRow, nCol - 1 , nArea);
        }
	}

};
```