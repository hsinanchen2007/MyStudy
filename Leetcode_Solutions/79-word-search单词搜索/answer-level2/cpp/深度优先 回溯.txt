```
class Solution
{
public:
	vector<int> temp;	//记录word第一个字母出现的位置 方便后续遍历
	string line;		//word的复制，方便dfs中对比
	bool res=false;		//记录答案

	void locate(vector<vector<char>> board, char c, vector<vector<bool>>& visited)//记录word第一个字母出现的位置 方便后续遍历
	{
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (c!=board[i][j] || visited[i][j])
					continue;
				else
				{
					temp.push_back(i);
					temp.push_back(j);
				}
			}
		}
		return;
	}

	//深度优先遍历
	void DFS(vector<vector<char>>& board, int c, vector<vector<bool>>& visited, int row, int col)
	{
		if (res == true)	//如果答案已经有了 直接返回
			return;
		if (c == line.size())	//判断是否检测到最后了 是则返回答案
		{
			res = true;
			return;
		}
		if (row > board.size() - 1 || col > board[0].size() - 1 || row < 0 || col < 0 || visited[row][col]) //判断是否越界
			return;
		if (line[c] != board[row][col])	//字符不相等 返回
			return;


		if (line[c] == board[row][col] && !visited[row][col])	//字符相等且 当前字母未被访问
		{
			visited[row][col] = true;
			DFS(board, c + 1, visited, row - 1, col);
			DFS(board, c+1, visited, row + 1, col); //上下右左 一次查询是否对应			
			DFS(board, c+1, visited, row, col + 1);
			DFS(board, c+1, visited, row, col - 1);
			visited[row][col] = false; //回溯 当前字符不能找到有效答案，将当前字符状态回调为未被访问
		}
	}

	bool exist(vector<vector<char>>& board, string word)
	{
		line = word;
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));	//设置数组记录该字符是否被访问过
		locate(board,word[0],visited);
		for (int i = 0; i < temp.size() / 2; i++)		//遍历所有第一个字符相同的位置
		{
			DFS(board, 0, visited, temp[0 + i * 2], temp[1 + i * 2]);
		}
		
		return res;
	}
};
```
