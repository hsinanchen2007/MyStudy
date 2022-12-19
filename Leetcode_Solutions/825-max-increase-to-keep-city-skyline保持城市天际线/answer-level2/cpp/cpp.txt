### 解题思路
短板效应

### 代码

```cpp
class Solution {	
	public:
		int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
			vector<int> row;
			vector<int> col;
			int row_size = grid.size();
			int col_size = grid[0].size();
			row.resize(col_size);
			col.resize(row_size);
			int ret = 0;
			for(int i=0;i<row_size;i++){
				for(int j=0;j<col_size;j++){
					row[j] = max(row[j],grid[i][j]);
					col[i] = max(col[i],grid[i][j]);
				}
			}

			for(int i=0;i<row_size;i++){
				for(int j=0;j<col_size;j++){
					int cur_max = min(row[j],col[i]);
					int cur_dif = cur_max - grid[i][j];
					ret+=(cur_dif > 0)?cur_dif:0;
				}
			}

			return ret;
		}
};
```