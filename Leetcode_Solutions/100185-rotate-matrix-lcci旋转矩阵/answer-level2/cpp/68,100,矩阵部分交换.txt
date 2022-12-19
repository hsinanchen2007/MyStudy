### 解题思路
需要注意矩阵左上部分每个元素都旋转到了右上部分，右上部分又旋转到了右下部分。。。
相当于转了一圈，
左上(i,j)对应：右上(j,n-i-1)，右下(n-i-1,n-j-1)，左下(n-j-1,i)
只需要对左上块部分进行相应的数据交换即可完成整个交换

### 代码

```cpp
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int c = n / 2;
		int r = (n + 1) / 2;//防止size为奇数的情况
		for(int i=0;i<c;i++)
			for (int j = 0; j < r; j++)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[n - j - 1][i];
				matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
				matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
				matrix[j][n - i - 1] = temp;
			}

	}
};

```