### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
bool is_ok(int col, int row, vector<int>& queue_pos) {
	for (int i = 0; i < row; i++) {
		if (queue_pos[i] == col || col + row == i + queue_pos[i] || col + i == row + queue_pos[i])
			return false;
	}
	return true;
}
void solve(int n, int row, vector<int>& queue_pos, vector<vector<string>>& input) {
	if (row == n)
	{
		vector<string> element;
		for (int j = 0;j < queue_pos.size();j++) {
			string temp(n, '.');
			temp[queue_pos[j]] = 'Q';
			element.push_back(temp);

		}
		input.push_back(element);
		//cout <<" get one" << endl;
		return;
	}
	for (int i = 0; i < n;i++) {
		//cout << "---------"<< row <<"-"<<i << endl;
		if (is_ok(i, row, queue_pos)) {
			//cout << row<< "-" << i << endl;
			queue_pos[row] = i;
			solve(n, row+1, queue_pos, input);
		}
	}
}
vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> output;
	vector<int> queue_pos(n, 0);
	solve(n, 0, queue_pos, output);
	return output;
}


};
```