### 解题思路
先固定列，找出列里最大的元素，得到该元素所在的行tagi。
现在固定行tagi，找出这一行中最小的元素，得到该元素所在的列tagj，现在就算要看看这个最大元素与最小元素是否相等。
于是我将tagj与原本固定的列比较，如果相等，则将元素加入结果数组result中。

### 代码

```cpp
class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		int m = matrix.size();//矩阵行数
		int n = matrix[0].size();//矩阵列数
		vector<int> result;

		for (int j = 0; j < n; j++)
		{
			int max = matrix[0][j];
			int tagi=0;
			for (int i=1; i < m; i++) {
				if (matrix[i][j] >max)
                {
					max = matrix[i][j];
				    tagi = i;
                }
			}
			int min = matrix[tagi][0];
			int tagj = 0;
			for (int k=1; k < n; k++)
			{
				if (matrix[tagi][k] <min)
                {
					min = matrix[tagi][k];
				    tagj = k;
                }
			}
			if (tagj == j)
				 result.push_back(matrix[tagi][tagj]);
		}
        return result;
	}
};
```