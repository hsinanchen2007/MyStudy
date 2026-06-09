### 思路
1. 先选择**突出结点**（联通数量为 1 的结点，上下左右只有 1 边有金矿）作为入口，并永久 visited 这个结点。
   > 如果有**突出结点**，且这个结点是最优解，那么在探索**突出结点**时，就已经得到答案了。
   > 如果再从**拐角结点**探索，那么如果有更优解，绝对不会包含之前的**突出结点**，所以可以永久 visited 这个结点。
   11. 对这些结点使用 dfs 探索，途中的 visited 作为回溯使用。
2. 再选择某一个方向（┌  ┐  └  ┘）**拐角结点**（联通数量为 2 的拐角结点，且不是一条直线）作为入口。
   > 如果含有**突出结点**的不是最优解，那么相当于没有**突出结点**。
   > 没有**突出结点**，意味着可以形成回路，从**拐角结点**开始探索，必能访问所有。
   > 因为要保证回路，所以任一个方向的**拐角结点**都可以，不需要全部方向。
   > 可以通过下面的用例来验证。
   21. 对这些结点使用 dfs 探索，途中的 visited 作为回溯使用。


### 答题
```C++
int getNextNum(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& dd, vector<vector<int>>& m)
{
	int i = 0;	
	int flag = 0;
	for (auto& d : dd)
	{
		int dx = x + d[0];
		int dy = y + d[1];
		if (dx < 0 || dx >= grid.size()) continue;
		if (dy < 0 || dy >= grid[0].size()) continue;
		if (grid[dx][dy] == 0) continue;
		i += 1;
		flag += d[0] + d[1];
	}
	if (flag == 2)	// 记录拐角结点
	{
		m.push_back({ x, y });
	}
	return i;
}

void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& dd, vector<vector<int>>& vi, int gain, int &ans)
{
	gain += grid[x][y];
	ans = max(ans, gain);
	for (auto &d : dd)
	{
		int dx = x + d[0];
		int dy = y + d[1];
		if (dx < 0 || dx >= grid.size()) continue;
		if (dy < 0 || dy >= grid[0].size()) continue;
		if (grid[dx][dy] == 0) continue;
		if (vi[dx][dy] == 1) continue;
		vi[dx][dy] = 1;	// 回溯
		dfs(grid, dx, dy, dd, vi, gain, ans);
		vi[dx][dy] = 0;
	}
}

int getMaximumGold(vector<vector<int>>& grid) 
{
	vector<vector<int>> dd = { {0,1},{0,-1},{1,0},{-1,0} };
	vector<vector<int>> vi(grid.size(), vector<int>(grid[0].size(), 0));

	vector<vector<int>> m;
	int ans = 0;
	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j] == 0) continue;
			int nextNum = getNextNum(grid, i, j, dd, m);
			if (nextNum == 0)
			{
				ans = max(ans, grid[i][j]);
				continue;
			}
			if (nextNum > 1) continue;
			// 处理突出结点
			vi[i][j] = 1;	// 永久
			dfs(grid, i, j, dd, vi, 0, ans);
		}
	}
    if (!m.empty())	// 处理拐角结点
	{
		for (auto &v : m)
		{
			int i = v[0];
			int j = v[1];
			vi[i][j] = 1;	// 回溯
			dfs(grid, i, j, dd, vi, 0, ans);
			vi[i][j] = 0;	// 回溯
		}
    }
	return ans;
}
```

### 测试用例
补充几个测试用例。
1. **孤岛结点**为最大值
```
输入：[[10,0,0],[0,1,1],[0,1,10]]
输出：13
[10, 0, 0]
[ 0, 1, 1]
[ 0, 1,10]
```

2. 无**突出结点**
```
输入：[[1,1,0,1,1],[10,1,0,1,10],[0,1,1,1,0],[0,1,1,0,0]]
输出：31
[ 1, 1, 0, 1, 1]
[10, 1, 0, 1,10]
[ 0, 1, 1, 1, 0]
[ 0, 1, 1, 0, 0]
```

3. 有**突出结点**但是结果不包含此节点
```
输入：[[0,0,0,1,0],[1,1,1,1,10],[1,10,0,1,1]]
输出：27
[ 0, 0, 0, 1, 0]
[ 1, 1, 1, 1,10]
[ 1,10, 0, 1, 1]
```

4. 对上一个用例进行翻转和镜像的用例
```
输入：[[1,10,0,1,1],[1,1,1,1,10],[0,0,0,1,0]]
输出：27
[ 1,10, 0, 1, 1]
[ 1, 1, 1, 1,10]
[ 0, 0, 0, 1, 0]
```

```
输入：[[0,1,1],[0,1,10],[0,1,0],[1,1,1],[0,10,1]]
输出：27
[ 0, 1, 1]
[ 0, 1,10]
[ 0, 1, 0]
[ 1, 1, 1]
[ 0,10, 1]
```

```
输入：[[1,1,0],[10,1,0],[0,1,0],[1,1,1],[1,10,0]]
输出：27
[ 1, 1, 0]
[10, 1, 0]
[ 0, 1, 0]
[ 1, 1, 1]
[ 1,10, 0]
```

### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

