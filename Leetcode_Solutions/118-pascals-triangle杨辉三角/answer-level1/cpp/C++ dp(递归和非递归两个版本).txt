### 解题思路
动态规划

初始值
![image.png](https://pic.leetcode-cn.com/eb7c322c64ba7e655396e6cc10a156a57b14e3d2ad2b3ea6e6176578ceb12f62-image.png)
状态转移
![image.png](https://pic.leetcode-cn.com/7ac219105d259eea01d7160ea97ca44491bab7e3ad7f02157fdacc5972442e4f-image.png)


两个版本：非递归和递归

### 代码

#### 非递归
```cpp
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> dp(numRows);
		for (int i=0;i<numRows;i++)
		{
			for (int j=0;j<=i;j++)
			{
				if (i == 0 && j == 0 || j == 0 || j == i) dp[i].push_back(1);
				else dp[i].push_back(dp[i - 1][j] + dp[i - 1][j - 1]);
			}
		}
		return dp;
	}
};
```

#### 递归
```cpp
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> dp(numRows);
		int row = 0;
		int col = 0;
		generateRec(row, col, dp);
		return dp;
	}
	void generateRec(int& row, int& col, vector<vector<int>>& dp) {
		if (row >= dp.size()) return;
		//初始值
		if (row == 0 && col == 0 || col == 0 || col == row) dp[row].push_back(1);
		else
		{
			//状态转移
			dp[row].push_back(dp[row - 1][col] + dp[row - 1][col - 1]);
			//改变row,col
			if (col == row) {//行、列相等
				col = 0;
				row++;
			}
			else if (col < row)//行<列
			{
				col++;
			}
			//递归
			generateRec(row, col, dp);
		}
	}
};
```