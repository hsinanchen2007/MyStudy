### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
		if (grid.size() == 0) { return 0; }
		int row = grid.size(), col = grid.at(0).size();
		int ans = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid.at(i).at(j) != 0) {
					ans += 2;
					//上方增加的表面积
					if (i != 0) {
						ans += (grid.at(i).at(j) - grid.at(i - 1).at(j) > 0) ? grid.at(i).at(j) - grid.at(i - 1).at(j) : 0;
					}
					else {
						ans += grid.at(i).at(j);
					}
					//下方增加的表面积
					if (i != row - 1) {
						ans += (grid.at(i).at(j) - grid.at(i + 1).at(j) > 0) ? grid.at(i).at(j) - grid.at(i + 1).at(j) : 0;
					}
					else {
						ans += grid.at(i).at(j);
					}
					//左方增加的表面积
					if (j != 0) {
						ans += (grid.at(i).at(j) - grid.at(i).at(j-1) > 0) ? grid.at(i).at(j) - grid.at(i).at(j-1) : 0;
					}
					else {
						ans += grid.at(i).at(j);
					}
					//右方增加的表面积
					if (j != col-1) {
						ans += (grid.at(i).at(j) - grid.at(i).at(j + 1) > 0) ? grid.at(i).at(j) - grid.at(i).at(j + 1) : 0;
					}
					else {
						ans += grid.at(i).at(j);
					}
				}
			}
		}
		return ans;
	}
};
```