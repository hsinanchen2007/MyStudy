### 解题思路
思路：多个腐烂橘子，让其均入队，对这些腐烂橘子同时广度优先使其周围橘子腐烂

算法：
1、先找出腐烂橘子，添加进queue
2、出队时，让当前腐烂橘子四周的新鲜就只都变为腐烂，即grid[tempX][tempY]=2;
3、用minute记录腐烂的持续时间，如果每一层的内一层橘子有腐烂，则自增1
4、检查网格中是否还有新鲜的的橘子
-	有，返回-1
-  没有，返回minute


### 代码

```cpp
class Solution {
public:
	//辅助定位——BFS常用
	array<int, 4> dx = { -1,1,0,0 };//上、下、左、右
	array<int, 4> dy = { 0,0,-1,1 };
	int orangesRotting(vector<vector<int>>& grid) {
		int minute = 0;//腐烂时间
		queue<pair<int, int>> q;//存储所有烂橘子
		for (int x = 0; x < grid.size(); x++)
		{
			for (int y = 0; y < grid[0].size(); y++)
			{
				if (grid[x][y] == 2)
				{
					q.push({ x,y });//所有烂橘子依次入队
				}
			}
		}
		//多源广度优先
		while (!q.empty())
		{
			int qSize = q.size();
			for (int i = 0; i < qSize; i++)//多源广度优先
			{
				pair<int, int> front = q.front();//首元素
				q.pop();//首元素出队
				//进行四个方向的污染
				for (int i = 0; i < 4; i++)
				{
					int tempX = front.first + dx[i];
					int tempY = front.second + dy[i];
					//存储是否越界的值
					bool noOver = (tempX >= 0 && tempX < grid.size() && tempY >= 0 && tempY < grid[0].size());
					//未越界且该橘子为新鲜橘子
					if (noOver && grid[tempX][tempY] == 1)
					{
						grid[tempX][tempY] = 2;//污染该橘子
						q.push({ tempX,tempY });
					}
				}
			}
			if (!q.empty()) minute++;//有内一层橘子腐烂（进入队列），则不为空，minute增加
		}
		//检查是否还有新鲜橘子
		for (int i=0;i<grid.size();i++)
		{
			for (int j=0;j<grid[i].size();j++)
			{
				if (grid[i][j] == 1) return -1;
			}
		}
		//返回时间
		return minute;
	}
};
```