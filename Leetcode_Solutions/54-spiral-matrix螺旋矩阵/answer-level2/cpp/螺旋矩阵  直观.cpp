采用最直观的方法，按照螺旋的顺序，先横向，到最右边在向下，触底后向左，到倒数第二个之后开始向上
以x,y分别表示矩阵的行数和列数，以此作为边界，只是在旋转过程中由外圈向内圈这两个值要相应的减少
如果是n * n的矩阵，用边界卡就够了，但是n* m的矩阵这样可能会多输出一个，所以添加count值来保证不多转一个
代码如下
```
vector<int>ans;
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int x = matrix.size(), n = matrix.size();
		if (x <= 0)
			return ans;
		int y = matrix[0].size(), m = matrix[0].size();
		int sum = x * y;
		int i = 0, j =0,count = 0;
		while (x > 0 && y>0) {
			while (j < y)
			{
				ans.push_back(matrix[i][j]);
				j++;
				count++;
			}
			if (count >= sum)break;
			j--; i++;
			while (i < x)
			{
				ans.push_back(matrix[i][j]);
				i++;
				count++;
			}
			if (count >= sum)break;
			i--; j--;
			while (j > m - y)
			{
				ans.push_back(matrix[i][j]);
				j--;
				count++;
			}
			if (count >= sum)break;
			while (i > n - x)
			{
				ans.push_back(matrix[i][j]);
				i--;
				count++;
			}
			if (count >= sum)break;
			i++; j++;
			x--;y--;
		}
		return ans;
	}
```
