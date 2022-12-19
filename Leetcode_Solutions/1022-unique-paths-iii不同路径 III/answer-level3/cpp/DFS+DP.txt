### 解题思路
将题目看成是某个状态的解，如果两个状态的起始坐标和先前走过的路径相同，那么这两个状态可以归为同一类，其结果一定相同，可以通过构建dp数组达到剪枝目的。用bitset来记录访问过的节点，对表格中的每个点，维护一个map<Bitset_20,int>来存储某个节点之前走过的访问路径对应的解。Bitset是自定义的结构体，为了提供比较大小的重载函数，才定义这样的结构体，否则用map会报错。

### 代码

```cpp
class Solution {
public:
struct Bitset_20
{
	bitset<20>Bit;
	friend bool operator<(const Bitset_20&a, const Bitset_20&b)
	{
		return a.Bit.to_ulong() < b.Bit.to_ulong();
	}
};
int dfs4(Bitset_20&bits, int x, int y, int length, map<Bitset_20, int>**dp,int w,int h,vector<vector<int>>&grid,int curr)
{
	if (grid[x][y] == 2 && curr != length)
	{
		bits.Bit.set(x*w + y, 0);
		return 0;
	}
	if (curr == length)
		if (grid[x][y] == 2)
		{
			bits.Bit.set(x*w + y, 0);
			return 1;
		}
		else {
			bits.Bit.set(x*w + y, 0);
			return 0;
		}
	else if (curr > length)
		return 0;
	bits.Bit.set(x*w + y, 1);
	if (dp[x][y].count(bits) != 0)
	{
		int re = dp[x][y][bits];
		bits.Bit.set(x*w + y, 0);
		return re;
	}
	else
	{
		int re = 0;
		if(x+1<h)
			if (grid[x + 1][y] != -1&& grid[x + 1][y] != 1 && !bits.Bit[(x + 1)*w + y])
			{
				re += dfs4(bits, x + 1, y, length, dp, w, h, grid,curr+1);
		    }
		if (x -1>=0)
			if (grid[x - 1][y] != -1&& grid[x - 1][y] != 1 &&!bits.Bit[(x-1)*w+y])
			{
				re += dfs4(bits, x - 1, y, length, dp, w, h, grid,curr+1);
			}
		if (y + 1 < w)
			if (grid[x][y+1] != -1&& grid[x][y + 1] != 1 && !bits.Bit[(x)*w + y+1])
			{
				re += dfs4(bits, x, y+1, length, dp, w, h, grid,curr+1);
			}
		if (y-1 >=0)
			if (grid[x][y-1] != -1&& grid[x][y - 1] != 1 && !bits.Bit[(x)*w + y-1])
			{
				re += dfs4(bits, x, y-1, length, dp, w, h, grid,curr+1);
			}
		dp[x][y][bits] = re;
		bits.Bit.set(x*w + y, 0);
		return re;
	}
}
    int uniquePathsIII(vector<vector<int>>& grid) {
    int w = grid[0].size();
	int h = grid.size();
    if(w*h==1)
    return 0;
    if(w*h==2)
    return 1;
	bool**access = new bool*[h];
	map<Bitset_20, int>**dp = new map<Bitset_20, int>*[h];
	for (int i = 0; i < h; i++)
	{
		access[i] = new bool[w];
		dp[i] = new map<Bitset_20, int>[w];
		for (int j = 0; j < w; j++)
		{
			access[i][j] = false;
			dp[i][j] = map<Bitset_20, int>();
		}
	}
	int start_x;
	int start_y;
	int length = w * h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (grid[i][j] == 1)
			{
				start_x = i;
				start_y = j;
			}
			else if (grid[i][j] == -1)
				length--;
	Bitset_20 bits;
	bits.Bit.reset();
	int re = dfs4(bits, start_x, start_y, length, dp, w, h, grid,1);
	return re;
    }
};
```