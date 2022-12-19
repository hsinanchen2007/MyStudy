### 解题思路
一层一层的旋转

### 代码

```cpp
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int length = matrix.size();
        if(length==0)
        return ;
		int n = length-1;
		int m = 0;
		while (m < n)
		{
			for (int i = m; i < n; ++i)
			{
				int one = matrix[m][i];
				matrix[m][i] = matrix[length - 1 - i][m];
				matrix[length - 1 - i][m] = matrix[n][length - 1 - i];
				matrix[n][length - 1 - i] = matrix[i][n];
				matrix[i][n] = one;
			}
			m++;
			n--;
		}
	}
};
```