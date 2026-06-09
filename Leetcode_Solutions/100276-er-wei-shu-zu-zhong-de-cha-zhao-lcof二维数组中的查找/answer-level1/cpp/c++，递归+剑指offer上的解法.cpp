//1.采用深度优先搜索的方法
//执行用时 :88 ms, 在所有 C++ 提交中击败了5.08% 的用户
//内存消耗:13 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
	bool dfs(vector<vector<int>>&matrix, int cur_i, int cur_j, int target) {
		if (matrix[cur_i][cur_j] == target)
			return true;
		else
			return false;
		//三个方向：往右,往下，往右下角
		int di[3] = { 1,0,1 };
		int dj[3] = { 0,1,1 };
		for (int index = 0; index != 3; ++index) {
			int next_i = cur_i + di[index], next_j = cur_j + dj[index];
			if (dfs(matrix, next_i, next_j, target))
				return true;
		}
	}

	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		bool find = false;
		for (int i = 0; i < matrix.size(); ++i)
			for (int j = 0; j < matrix[0].size(); ++j)
				if (dfs(matrix, i, j, target))
					find = true;
		return find;
	}
};

//2.采用剑指offer上的方法，选取左下角或者右上角，排除一行或者一列的数据。
//执行用时 :60 ms, 在所有 C++ 提交中击败了11.82% 的用户
//内存消耗:13.2 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution{
public:
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
	bool found = false;
	
	if (matrix.size() == 0)
		return false;

	int column = 0, row = matrix.size() - 1; //从左下角开始出发
	while (column < matrix[0].size() && row >= 0) {
		if (matrix[row][column] == target) {
			found = true;
			break;
		}
		else if (matrix[row][column] < target) { 
			column++; //当前值比目标值小，说明当前值所在的这一列都不行，往右走，列数+1
		}
		else {
			//当前值比当目标值大，此时只能往上走了
			row--;
		}
	}
	return found;
}
};