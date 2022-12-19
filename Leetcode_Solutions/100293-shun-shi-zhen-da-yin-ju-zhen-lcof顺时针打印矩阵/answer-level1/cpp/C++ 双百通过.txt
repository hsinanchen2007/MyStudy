### 解题思路
***参考自剑指offer书籍***
1、把矩阵看成由若干个方向的圈组成，每次循环打印一个圈，打印圈从(i,i)点出发，直到循环结束，循环结束条件是什么呢？我们可以发现最后打印的圈的起点的i*2<row和col，因此可使用此条件作为循环结束条件
2、对于打印的每一圈，可以分为四种情况，对四种情况进行依次打印即可
### 代码

```cpp
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		
	
		//存储结果
		vector<int> result;
		//特判
		if (matrix.size()==0)
		{
			return result;
		}
        //打印每一圈
		int row = matrix.size();
		int col = matrix[0].size();
		int start = 0;
		while (row > start * 2 && col > start * 2)//循环结束条件
		{
			//输出一圈
			//该圈起点的对立位置
			int endX = row - 1 - start;
			int endY = col - 1 - start;
			//先输出从左到右
			for (int i = start; i <= endY; i++)
			{
				result.push_back(matrix[start][i]);
			}
			//如果存在从上到下
			if (start < endX)
			{
				for (int i = start + 1; i <= endX; i++)
				{
					result.push_back(matrix[i][endY]);
				}
			}
			//如果存在从右到左
			if (start < endX && start < endY)
			{
				for (int i = endY - 1; i >= start; i--)
				{
					result.push_back(matrix[endX][i]);
				}
			}
			//如果存在从上到下
			if (start < endX - 1 && start < endY)
			{
				for (int i = endX - 1; i > start; i--)
				{
					result.push_back(matrix[i][start]);
				}
			}
			//start增加
			start++;
		}
		return result;

	}
};
```