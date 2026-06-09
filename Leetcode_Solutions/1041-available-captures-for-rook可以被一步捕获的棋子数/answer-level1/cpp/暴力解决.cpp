### 解题思路
车只能按东南西北方向前进，注意车所走的路线 只能为起点所在的十字路线
所以只需要对四个方向上的卒进行捕获
### 代码

```cpp
class Solution {
public:
	int numRookCaptures(vector<vector<char>>& board) {
		int posx, posy,count=0;
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board.size(); j++)
				if (board[i][j] == 'R')
				{
					//得到车的位置
					posx = i;
					posy = j;
				}

		//判断车的四个方向
		for (int i = posx+1; i < board.size(); i++)
		{
			//遇到象停止
			if (board[i][posy] == 'B')
				break;
			if (board[i][posy] == 'p')
			{
				count++;
				break;
			}
		}

		for (int i = posx-1; i>=0; i--)
		{
			//遇到象停止
			if (board[i][posy] == 'B')
				break;
			if (board[i][posy] == 'p')
			{
				count++;
				break;
			}
		}

		for (int i = posy+1; i < board.size(); i++)
		{
			//遇到象停止
			if (board[posx][i] == 'B')
				break;
			if (board[posx][i] == 'p')
			{
				count++;
				break;
			}
		}

		for (int i = posy-1; i >=0; i--)
		{
			//遇到象停止
			if (board[posx][i] == 'B')
				break;
			if (board[posx][i] == 'p')
			{
				count++;
				break;
			}
		}

		return count;

	}
};

```