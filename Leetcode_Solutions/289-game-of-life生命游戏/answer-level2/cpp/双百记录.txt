### 解题思路
注意题目是同时更新，因此额外使用一个记录数组，另外使用向量数组简化代码

### 代码

```cpp
class Solution {
public:
	typedef struct
	{
		int x, y;
	}_dire;
	void gameOfLife(vector<vector<int>>& board) {
		vector<_dire> dire{ {-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0} };
		vector<vector<int>> record = board;
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[i].size(); j++)
			{
				//get alive
				int alive = 0;
				for (int k = 0; k < dire.size(); k++)
					if (i + dire[k].x >= 0 && i + dire[k].x < board.size() &&
						j + dire[k].y >= 0 && j + dire[k].y < board[i].size() &&
						board[i + dire[k].x][j + dire[k].y] == 1)
					{
						alive++;
					}
				if (alive < 2)
				{
					record[i][j] = 0; continue;
				}
				if (alive > 3)
				{
					record[i][j] = 0; continue;
				}
				if (alive == 3)
					record[i][j] = 1;
			}
		board = record;
	}
};
```