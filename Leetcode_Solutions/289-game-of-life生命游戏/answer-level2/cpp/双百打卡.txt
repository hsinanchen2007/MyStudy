### 解题思路
第一遍遍历，按照以下四个变化，更新每个细胞的值
0->1:-3
0->0:-2
1->1:3
1->0:2
第二遍遍历，根据自身的值，恢复成0和1
### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
		if (m == 0) return;
		int n = board[0].size();
		int dx[8] = { 0, 1, 0, -1, - 1, -1, 1, 1 };
		int dy[8] = { 1, 0, -1, 0, -1, 1,  -1, 1 };
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int count = 0;
				for (int k = 0; k < 8; k++)
				{
					int tx = j + dx[k];
					int ty = i + dy[k];
					if (tx >= 0 && tx < n && ty >= 0 && ty < m)
					{
						if (board[ty][tx] == 1 || board[ty][tx] == 2 || board[ty][tx] == 3) 
							count++;
					}
				}
				if (count >= 2 && count <= 3)
				{
					if (board[i][j] == 1) board[i][j] = 3;
					if (board[i][j] == 0 && count == 3) board[i][j] = -3;
				}
				else
				{
					if (board[i][j] == 0) board[i][j] = -2;
					else board[i][j] = 2;
				}
			}
		}
		for (auto& bo : board)
		{
			for (auto& b : bo)
			{
				if (b == 2 || b == -2) b = 0;
				if (b == 3 || b == -3) b = 1;
			}
		}
		return;
    }
};
```