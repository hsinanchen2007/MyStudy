```c++
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> result;
	// 分配好n*n的数组内存
	vector<int> rowVector;
	for (int i = 0; i < n; i++)
		rowVector.push_back(0);
	for (int i = 0; i < n; i++)
		result.push_back(rowVector);

	int currentDigit = 1;

	// 从外层到内层开始赋值
	for (int i = 0; i <= n/2; i++)
	{
		//每层都有四条边赋值
		// 上
		for (int j = i; j < n-i; j++)
		{
			result[i][j] = currentDigit;
			currentDigit++;
		}
		// 右
		for (int j = i+1; j < n-i; j++)
		{
			result[j][n - i - 1] = currentDigit;
			currentDigit++;
		}
		// 下
		for (int j = n-i-2; j >= i; j--)
		{
			result[n - i - 1][j] = currentDigit;
			currentDigit++;
		}
		// 左
		for (int j = n-i-2; j > i ; j--)
		{
			result[j][i] = currentDigit;
			currentDigit++;
		}
	}

	return result;
}
};
```
