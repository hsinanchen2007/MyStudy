举个例子：
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

先将其进行转置操作，及对角线互换
[
  [1,4,7],
  [2,5,8],
  [3,6,9]
],

再将其每行的首尾互换
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
],

如果为n为偶数的话
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

将其转置
[
  [ 5, 2,13,15],
  [ 1, 4, 3,14],
  [ 9, 8, 6,12],
  [11,10, 7,16]
], 

再将每行的两边都互换
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
], 

代码如下:
```
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() <= 1) return;
		//转置矩阵
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = i; j < matrix.size(); j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;
			}
		}

		//对换首尾
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix.size() / 2; j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[i][matrix.size() - 1 - j];
				matrix[i][matrix.size() - 1 - j] = tmp;
			}
		}
	}
};
```
