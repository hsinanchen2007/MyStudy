### 解题思路

1，熟懂题意，一开始当作是染色问题如岛的数量，打算用DFS,看懂就简单了
2，就是求棋盘中R上下左右能直接接触到的p的数量，最大为4
3，先循环求R,再以R为中心上下左右加减
4，注意判断B和越界

### 代码

```cpp
class Solution {
public:
int n;
int GetPnums(vector<vector<char>>& board, int x, int y, int dx, int dy) {//---x,y表示坐标，a,b表示正负
	while (x >= 0 && x < n && y >= 0 && y < n && board[x][y] != 'B')
	{
		if (board[x][y] == 'p')
			return 1;
		x += dx;
		y += dy;
	}
	return 0;
}
int numRookCaptures(vector<vector<char>>& board) { //R、.、B、p
	n = board.size();
	int sum = 0;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };//---四连通数组
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j] == 'R')
				for (int num = 0; num < 4; num++)
					sum += GetPnums(board, i, j, dx[num], dy[num]);
	return sum;
}
};
```