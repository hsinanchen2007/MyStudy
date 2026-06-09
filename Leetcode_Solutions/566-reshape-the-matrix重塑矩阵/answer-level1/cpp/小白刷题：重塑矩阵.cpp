方法一：一个数一个数放，循环遍历，不过费时间

方法二：两矩阵中数的顺序是一样的，[i,j]对应的元素为第(i*col+j)个，因此可以将两矩阵元素一一对应

代码：
```
class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int row = nums.size();
		int col = nums[0].size();
		if (row * col != r * c)
			return nums;
		else {
			vector<vector<int>> ans(r, vector<int>(c));
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++)
					ans[i][j] = nums[(i * c + j) / col][(i * c + j) % col];
			}
			return ans;
		}
	}
};
```
