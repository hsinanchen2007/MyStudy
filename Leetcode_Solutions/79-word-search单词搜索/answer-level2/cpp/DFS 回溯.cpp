很像迷宫题有没有入口到出口路线的问题。
这里的问题是不确定入口在哪里，所以可以遍历整个网格，只要符合单词的第一个字母，就开始backtrack递归，按四个方向查，如果在边界内，且没有走过，就走下去，直到找到单词为止，找到的话就不用再找其他可能的入口了，直接返回true；没有的话就按下一个入口位置开始向四周找
```
class Solution {
public:
	vector<vector<char>>Board;
	
	vector<int>dirx{0,1,0,-1};
	vector<int>diry{1,0,-1,0};
	bool flag;
	string word2;
	bool isok(string cur) {
		for (int i = 0; i < cur.length(); i++)
		{
			if (cur[i] != word2[i])
				return false;
		}
		return true;
	}
	void backtrack(int x, int y, string cur, vector<vector<bool>>visited)
	{
		int boardx = Board.size();
		int boardy = Board[0].size();
		if (cur == word2) {
			flag = true;
			return;
		}
		if (isok(cur) == false )
		{
				return;
		};
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dirx[i];
			int ny = y + diry[i];
			if (nx < 0 || ny < 0 || nx >= boardx || ny >= boardy)
				continue;
			if (visited[nx][ny] == false)
			{
				
				cur += Board[nx][ny];
				visited[nx][ny] = true;
				backtrack(nx, ny, cur, visited);
				if (flag == true)
					return;
				cur.pop_back();
				visited[nx][ny] = false;
			}
		}
	}
	
	bool exist(vector<vector<char>>& board, string word) {
		flag = false;
		Board = board;
		word2 = word;
		if (board.size() == 0)
			return false;
		vector<vector<bool>>visited;
		
		string cur;
		int bs = board.size(), bs2 = board[0].size();
		for (int i = 0; i < bs; i++)
		{
			vector<bool>temp;
			for (int j = 0; j < bs2; j++)
			{
				temp.push_back(false);
			}
			visited.push_back(temp);
		}
		for (int i = 0; i < bs; i++)
		{
			for (int j = 0; j < bs2; j++) {
				if (board[i][j] == word[0])
				{
					flag = false;
					cur = "";
					cur += board[i][j];
					visited[i][j] = true;
					backtrack(i, j, cur, visited);
					if (flag == true)
						return true;
					else
						visited[i][j] = false;
				}
			}
		}
		
		
		
		return flag;
	}
};
```
