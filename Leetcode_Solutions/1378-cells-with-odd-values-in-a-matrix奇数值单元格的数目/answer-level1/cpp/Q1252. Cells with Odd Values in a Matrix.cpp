### 模拟
直接按照题意模拟即可
```
class Solution {
public:
	int oddCells(int n, int m, vector<vector<int>>& indices) {
		vector<vector<bool>> cells(n, vector<bool>(m, false));
		for (size_t i = 0; i < indices.size(); ++i) {
			for (int iCol = 0; iCol < m; ++iCol)
				cells[indices[i][0]][iCol] = !cells[indices[i][0]][iCol];
			for (int iRow = 0; iRow < n; ++iRow)
				cells[iRow][indices[i][1]] = !cells[iRow][indices[i][1]];
		}

		size_t nOddCells = 0;
		for (int iRow = 0; iRow < n; ++iRow)
			for (int iCol = 0; iCol < m; ++iCol)
				nOddCells += (cells[iRow][iCol]);
		return nOddCells;
	}
};
```
我果真不适合写题解，写文章啊！