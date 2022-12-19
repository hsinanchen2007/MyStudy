### 解题思路
本题可选思路为BFS和DFS。

如果使用DFS，则会遇到正在搜索的路径影响最终结果判断的问题。
这时的处理方法通常是只将最顶层的遍历结果进行记忆，但是会影响效率（本题超时）。

因此使用BFS。具体思路是：
（1）先找到所有与1相邻的0，放入队列；
（2）开始广度遍历，将所有相邻的未处理的1放入新队列，并且将这些点的结果输出；
（3）继续迭代直到队列为空。

此题为典型的适合BFS解决的问题。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define QUE_SIZE		10000
#define FLAGS_(a, b)	flags[(a) * col + (b)]

typedef struct _info_st_
{
	int y;
	int x;
}info_st;

info_st * que0_[QUE_SIZE];
info_st * que1_[QUE_SIZE];

info_st *que0;
info_st *que1;

bool is_next_1(int** matrix, int row, int col, int y, int x)
{
	if(y > 0 && matrix[y - 1][x] == 1)
	{
		return true;
	}

	if(y < row - 1 && matrix[y + 1][x] == 1)
	{
		return true;
	}

	if(x > 0 && matrix[y][x - 1] == 1)
	{
		return true;
	}

	if(x < col - 1 && matrix[y][x + 1] == 1)
	{
		return true;
	}

	return false;
}

//【算法思路】BFS。先找到所有与1相邻的0，然后逐步推算。
//DFS存在前面路径点影响后面判断的情况。
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
	int row  = matrixSize;
	int col  = matrixColSize[0];

	int **res = (int **)calloc(row, sizeof(int*));
	int *res_col = (int *)calloc(row, sizeof(int));

	for(int i = 0; i < row; i++)
	{
		res[i] = (int *)calloc(col, sizeof(int));
		res_col[i] = col;
	}

	int *flags = (int *)calloc(row * col, sizeof(int));

	que0 = que0_;
	que1 = que1_;

	int qsize0 = 0;
	int qsize1 = 0;

	//初始化队列
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(matrix[i][j] == 0)
			{
				if(is_next_1(matrix, row, col, i, j))
				{
					que0[qsize0].y = i;
					que0[qsize0].x = j;
					qsize0++;

					//printf("[%d, %d] ", i, j);
				}
				
				FLAGS_(i, j) = 1;
			}
		}
	}
    //printf("\n");

	int cnt = 0;
	while(qsize0 > 0)
	{
/*
		for(int i = 0; i < qsize0; i++)
		{
			printf("[%d, %d] ", que0[i].y, que0[i].x);
		}
		printf("\n");
*/
		cnt++;

		for(int i = 0; i < qsize0; i++)
		{
			int y = que0[i].y;
			int x = que0[i].x;

			if(y > 0 && matrix[y - 1][x] == 1 && FLAGS_(y - 1, x) == 0)
			{
				res[y - 1][x] = cnt;
				FLAGS_(y - 1, x) = 1;

				que1[qsize1].y = y - 1;
				que1[qsize1].x = x;
				qsize1++;
			}

			if(y < row - 1 && matrix[y + 1][x] == 1 && FLAGS_(y + 1, x) == 0)
			{
				res[y + 1][x] = cnt;
				FLAGS_(y + 1, x) = 1;

				que1[qsize1].y = y + 1;
				que1[qsize1].x = x;
				qsize1++;
			}

			if(x > 0 && matrix[y][x - 1] == 1 && FLAGS_(y, x - 1) == 0)
			{
				res[y][x - 1] = cnt;
				FLAGS_(y, x - 1) = 1;

				que1[qsize1].y = y;
				que1[qsize1].x = x - 1;
				qsize1++;
			}

			if(x < col - 1 && matrix[y][x + 1] == 1 && FLAGS_(y, x + 1) == 0)
			{
				res[y][x + 1] = cnt;
				FLAGS_(y, x + 1) = 1;

				que1[qsize1].y = y;
				que1[qsize1].x = x + 1;
				qsize1++;
			}
		}

		info_st *tmpq = que0;
		que0 = que1;
		que1 = tmpq;

		qsize0 = qsize1;
		qsize1 = 0;
	}

	*returnSize = row;
	*returnColumnSizes = res_col;
	return res;
}
```