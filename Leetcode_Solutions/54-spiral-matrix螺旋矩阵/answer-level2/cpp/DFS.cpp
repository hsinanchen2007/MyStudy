### 解题思路
此题抽象成一个DFS的遍历问题。
从0,0开始，第一次的方向是往右走，然后如果右的方向走不通了，就遍历四个方向，找到能走的方向继续走。

需要注意的问题：
空输入，需要直接返回；
不能用-1，标记已经被访问的元素，注意输入的范围；可以使用INT_MIN或者是INT_MAX来替代。

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};
	bool IsNodeValid(vector<vector<int>>& matrix, int x, int y)
	{
		if (x < 0 || x >= matrix.size() || y >= matrix[0].size() || y < 0) {
			return false;
		}
		if (matrix[x][y] == INT_MIN) {
			return false;
		}
		return true;
	}
	void RefreshRes(vector<vector<int>>& matrix, vector<int>& ans, pair<int, int> currentNode, int index) 
	{	
		int x = currentNode.first;
		int y = currentNode.second;
		if (IsNodeValid(matrix, x + dir[index][0], y + dir[index][1])) {
			ans.push_back(matrix[x + dir[index][0]][y + dir[index][1]]);
			matrix[x + dir[index][0]][y + dir[index][1]] = INT_MIN;
			RefreshRes(matrix, ans, make_pair(x + dir[index][0], y + dir[index][1]), index);
		} else {
			for (int i = 0; i < 4; i++) {
				int nextX = x + dir[i][0];
				int nextY = y + dir[i][1];
				if (IsNodeValid(matrix, nextX, nextY)) {
					ans.push_back(matrix[nextX][nextY]);
					matrix[nextX][nextY] = INT_MIN;
					RefreshRes(matrix, ans, make_pair(nextX, nextY), i);
				}	
			}
		}
	}
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty()) {
			return vector<int>();
		}
		vector<int> ans(1, matrix[0][0]);
		matrix[0][0] = INT_MIN;
		RefreshRes(matrix, ans, make_pair(0,0), 2);
		return ans;
    }
};
```