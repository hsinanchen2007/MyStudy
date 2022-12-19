### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//取r,c值，pos = r*m+c;   5/4=1..1 		//二分法
		if (matrix.empty())
			return false;
        if (matrix[0].empty())
			return false;
		int rows = matrix.size();
		int cols = matrix[0].size();
		int total = rows * cols, right = total,left = 0;
		
		while (left <= right)
		{
			int pos = (left + right) / 2;
			int r = pos / cols;
			int c = pos % cols;
			if (r >= rows || c >= cols)
				return false;
			int v = matrix[r][c];
			if (v == target)
				return true;
			else if (v < target)
				left = pos + 1;
			else
				right = pos - 1;
		}
		return false;
	}
};

```