### 解题思路
本题的规律，从矩阵的右上角分析，如果该值比target大，则舍弃该列，如果该值比target小，则舍弃该行，如果相等，则返回true

### 代码

```cpp
class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.size()==0)//边界条件
		{
			return false;
		}
		int row = 0;
		int col = matrix[0].size()-1;

		while (row<matrix.size()&&col>=0)
		{
			if (matrix[row][col]==target)
			{
				return true;
			}
			else if (matrix[row][col]>target)
			{
				col--;//舍弃列
			}
			else
			{
				row++;//舍弃行
			}
		}
		return false;
	}
};
```