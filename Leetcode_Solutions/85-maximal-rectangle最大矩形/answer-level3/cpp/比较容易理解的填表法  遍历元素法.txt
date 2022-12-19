生成两个表格 down[][] 和 right[][]  分别代表 节点 x 位置上，向下最大有几个元素，向右边有几个元素可用
例如
【1】【1】【1】
【1】【1】【0】
【0】【1】【0】

对应的 down:
【2】【3】【1】
【1】【2】【0】
【0】【1】【0】

对应的right:
【3】【2】【1】
【2】【1】【0】
【0】【1】【0】

然后两次遍历节点，有节点 [x][y]  如果 down[x][y] 非零，那么他的最低长度为 len = down[x][y]，

然后分别向左/右试探即可，只要左/右节点的 down 数值 down[x][y]，那么说明，往左或者往右可以扩展，每次扩展增加的面积依然为 len；

最后看是否大于max 如果是就更新。

示例表格元素[0][0] 通过down 计算的最大值为 down[0][0]=2; 面积为2；len=2; 
                                        down[0][1]>=2  面积 += 2；
                                        down[0][2] =1, 小于2 所以停止
                  通过righ 计算的最大值为 right[0][0] = 2;面积为2；len=2; 
                                        right[1][0] = 2; 面积 += 2；
                                        right[2][0] =0, 小于2 所以停止


```
if (matrix.empty() || matrix[0].empty()) return 0;
	vector<vector<int>> down(matrix.size(), vector<int>(matrix[0].size(), 0)); // x 节点下方有 ‘0’吗, 0表示有 ， 1表示没
	vector<vector<int>> right(matrix.size(), vector<int>(matrix[0].size(), 0));  // x 节点右边有 ‘0’吗


	for (int i = matrix.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if (i == matrix.size() - 1)
			{
				down[i][j] = matrix[i][j] - 48;
				continue;
			}

			if (matrix[i][j] == '1')
			{
				down[i][j] = down[i + 1][j] + 1;
			}
			else down[i][j] = 0;
		}
	}

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = matrix[0].size() - 1; j >= 0; j--)
		{
			if (j == matrix[0].size() - 1)
			{
				right[i][j] = matrix[i][j] - 48;
				continue;
			}

			if (matrix[i][j] == '1')
			{
				right[i][j] = right[i][j+1] + 1;
			}
			else right[i][j] = 0;
				
		}
	}



	int max = 0;

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if (down[i][j])
			{
				int area = down[i][j];
				int temp = area;

				int col = j + 1;
				while (col<matrix[0].size()&&down[i][col]>=down[i][j])
				{
					area += temp;
					col++;
				}
				if (area > max) max = area;

				col = j - 1;
				while (col >=0 && down[i][col] >= down[i][j])
				{
					area += temp;
					col--;
				}
				if (area > max) max = area;
			}
		}
	}


	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			// 横着的模式

			if (right[i][j])
			{
				int area = right[i][j];
				int temp = area;

				int line = i + 1;
				while (line < matrix.size() && right[line][j]>=right[i][j])
				{
					area += temp;
					line++;
				}
				if (area > max) max = area;

				line = i - 1;
				while (line >=0 && right[line][j] >= right[i][j])
				{
					area += temp;
					line--;
				}
				if (area > max) max = area;
			}
		}
	}

	return max;
```
