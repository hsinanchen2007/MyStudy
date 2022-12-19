唉，在周竞赛（虚拟）看到这道题我是崩溃的，我日，第一感觉就是肯定无法在剩余时间内做出来，绝望！！！！！
问最少推箱子次数，我的思考过程是这样的：
**1，如果不是推箱子，而是箱子自己跑，要多少次？**
显然，这是个最短路径问题，于是，BFS就出现在脑海。
**2,有个人怎么办？也就是说，上面的BFS路径不是说想取就能取，要求人可以走到箱子的后面。**
显然，这是问能否到达的问题，干脆也用BFS好了。
**3，最后，综合以上两个，BFS的状态就定义为（pushx,push_y,box_x,box_y）**，然后就，直接用队列照着跑出来就好了。也没什么优化，毕竟太菜，话说，这道题周竞赛真的有大佬限时敲出来吗？我还是平时就写好了BFS模板复制粘贴然后修改都来不及？唉，我太菜。
```

class Solution {
public:
	int minPushBox(vector<vector<char>> grid) {
		int m = grid.size();
		int n = grid[0].size();
		queue<vector<int>>q;
		bool isin[21][21][21][21] = { false };
		vector<int>B;
		vector<int>T;
		vector<int>S;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 'B')
				{
					B = { i,j };
				}
				if (grid[i][j] =='T')
				{
					T= { i,j };
				}
				if (grid[i][j] == 'S')
				{
					S = { i,j };
				}
			}
		}
		int delta[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
		for (int i = 0; i < 4; i++)
		{
			auto x = B[0] + delta[i][0];
			auto y = B[1] + delta[i][1];
			if (can_arrive(S[0], S[1], x, y, grid))
			{
				q.push({ x,y,B[0],B[1] });
				isin[x][y][B[0]][B[1]] = true;
				break;//找到一个入口就行
			}
		}
		size_t cur_level = 0;
		size_t cur_level_size = 1;
		size_t next_level_size = 0;
		size_t i = 0;
		grid[B[0]][B[1]] = '.';
		while (!q.empty())
		{
			auto cur_pos = q.front();
			q.pop();
			auto sx = cur_pos[0];
			auto sy = cur_pos[1];
			auto bx = cur_pos[2];
			auto by = cur_pos[3];
			if (bx == T[0] && by == T[1])
				return cur_level;
			grid[bx][by] = 'B';
			for (int i = 0; i < 4; i++)
			{
				auto x = cur_pos[2] + delta[i][0];
				auto y = cur_pos[3] + delta[i][1];//箱子的下一个位置
				if (x>=0&&x<m&&y>=0&&y<n&&grid[x][y] !='#')
				{
					auto push_x = cur_pos[2] - delta[i][0];
					auto push_y = cur_pos[3] - delta[i][1];//人推箱要站的位置
					if (push_x>=0&&push_x<m&&push_y>=0&&push_y<n&&!isin[bx][by][x][y]&&can_arrive(sx, sy, push_x, push_y, grid))
					{
						next_level_size++;
						q.push({bx,by,x,y });
						isin[bx][by][x][y] = true;
					}
				}
			}
			grid[bx][by] = '.';
			i++;//当前层次节点计数
			if (i == cur_level_size)
			{
				i = 0;
				cur_level_size = next_level_size;
				next_level_size = 0;
				cur_level++;
			}
		}
		return -1;
	}
	bool can_arrive(int x, int y, int tx, int ty, vector<vector<char>>&grid)
	{
		if (grid[tx][ty] == '#')
			return false;
		if (x == tx && y == ty)
			return true;
		int m = grid.size();
		int n = grid[0].size();
		queue<vector<int>>q;
		isin[21][21]={false};
		isin[x][y] = true;
		q.push({ x,y });
		int delta[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
		while (!q.empty())
		{
			auto cur_pos = q.front();
			q.pop();
			if (cur_pos[0]==tx&&cur_pos[1]==ty)
				return true;
			for (int i = 0; i < 4; i++)
			{
				auto next_x = cur_pos[0] + delta[i][0];
				auto next_y = cur_pos[1] + delta[i][1];
				if (next_x>=0&&next_x<m&&next_y>=0&&next_y<n&&grid[next_x][next_y] != '#'&&grid[next_x][next_y] != 'B'&&!isin[next_x][next_y])
				{
					isin[next_x][next_y] = true;
					q.push({ next_x,next_y });
				}
			}
		}
		return false;
	}
};
```
