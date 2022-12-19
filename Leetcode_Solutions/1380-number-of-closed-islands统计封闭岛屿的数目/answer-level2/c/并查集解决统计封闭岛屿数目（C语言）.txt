### 解题思路
联通类问题，使用并查集解决。

将边界和水域的father设置为0，然后将岛屿归并，最终不为0的根数目，即为封闭岛屿数目。

![image.png](https://pic.leetcode-cn.com/f16de8f80e30062a74856df4cb248d2669c2b13935f7855c6aac2097f6e2734c-image.png)

### 代码

```c

#define FA_(a, b)		fa[(a) * col + (b)]
#define FA_ID(a, b)		((a) * col + (b))

int find(int *fa, int x)
{
	if(fa[x] == x)
	{
		return x;
	}

	fa[x] = find(fa, fa[x]);

	return fa[x];
}

void join(int *fa, int x, int y)
{
	int xx = find(fa, x);
	int yy = find(fa, y);

	if(xx == yy)
	{
		return;
	}

	if(xx < yy)
	{
		fa[yy] = xx;
	}
	else
	{
		fa[xx] = yy;
	}
}

//【算法思路】并查集。边界设置为0，水域设置为0，所有陆地进行合并，最终非0的fa个数即为孤岛个数。
int closedIsland(int** grid, int gridSize, int* gridColSize){
	int row = gridSize;
	int col = gridColSize[0];

	int *fa = (int *)calloc(row * col, sizeof(int));

	for(int i = 0; i < row * col; i++)
	{
		fa[i] = i;
	}

	for(int i = 0; i < row; i++)
	{
		for(int j = 0;j < col; j++)
		{
			if(grid[i][j] == 1)
			{
				FA_(i, j) = 0;
			}
		}
	}

	for(int i = 0; i < row; i++)
	{
		FA_(i, 0) = 0;
		FA_(i, col - 1) = 0;
	}

	for(int j = 0; j < col; j++)
	{
		FA_(0, j) = 0;
		FA_(row - 1, j) = 0;
	}

	for(int i = 0; i < row; i++)
	{
		for(int j = 0;j < col; j++)
		{
            if(grid[i][j] == 0)
            {
                if(i > 0 && grid[i - 1][j] == 0)
                {
                    join(fa, FA_ID(i - 1, j), FA_ID(i, j));
                }

                if(j > 0 && grid[i][j - 1] == 0)
                {
                    join(fa, FA_ID(i, j - 1), FA_ID(i, j));
                }
            }
		}
	}

	int cnt = 0;
	for(int i = 0; i < row * col; i++)
	{
		if(find(fa, i) != 0 && find(fa, i) == i)
		{
			cnt++;
		}
	}

	return cnt;

}
```