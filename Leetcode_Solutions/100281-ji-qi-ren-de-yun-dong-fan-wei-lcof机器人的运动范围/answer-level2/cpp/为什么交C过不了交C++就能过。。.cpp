class Solution {
public:
int map[101][101] = { 0 };
void dfs(int x, int y, int m, int n)
{
	if (x >=m||y>=n||x<0||y<0)
		return;
	if (map[x][y] != 0)
		return;
	map[x][y] = 1;
	dfs(x + 1,y,m,n);
	dfs(x-1 , y, m, n);
	dfs(x , y + 1, m, n);
	dfs(x, y - 1, m, n);
}

int movingCount(int m, int n, int k)
{
	int sum = 0;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (i / 100 + i / 10 + i % 10 + j / 100 + j / 10 + j % 10 > k)
				map[i][j] = -1;
		}
	}
	dfs(0, 0, m, n);
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (map[i][j] == 1)
				sum++;
		}
	}
	return sum;
}
};```
class Solution {
public:
int map[101][101] = { 0 };
void dfs(int x, int y, int m, int n)
{
	if (x >=m||y>=n||x<0||y<0)
		return;
	if (map[x][y] != 0)
		return;
	map[x][y] = 1;
	dfs(x + 1,y,m,n);
	dfs(x-1 , y, m, n);
	dfs(x , y + 1, m, n);
	dfs(x, y - 1, m, n);
}

int movingCount(int m, int n, int k)
{
	int sum = 0;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (i / 100 + i / 10 + i % 10 + j / 100 + j / 10 + j % 10 > k)
				map[i][j] = -1;
		}
	}
	dfs(0, 0, m, n);
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (map[i][j] == 1)
				sum++;
		}
	}
	return sum;
}
};
```
