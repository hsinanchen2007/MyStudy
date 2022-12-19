```C++
bool exist(vector<vector<char>> &board, size_t i, size_t j, string word, unordered_set<size_t> visited)
{
	if (word.empty()) return true;
	if (board.size() == 0 || board.size() <= i) return false;
	if (board[0].size() == 0 || board[0].size() <= j) return false;
	if (visited.count(i * board[0].size() + j)) return false;
	
	if (board[i][j] != word.front()) return false;
	word = word.substr(1, word.size() - 1);
	visited.insert(i * board[0].size() + j);

	if (exist(board, i - 1, j, word, visited)) return true;
	if (exist(board, i + 1, j, word, visited)) return true;
	if (exist(board, i, j - 1, word, visited)) return true;
	if (exist(board, i, j + 1, word, visited)) return true;

	return false;
}

bool exist(vector<vector<char>>& board, string word) 
{
	unordered_map<char, int> map_board;
	unordered_map<char, int> map_word;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			map_board[board[i][j]]++;
		}
	}
	for (auto &c : word)
	{
		map_word[c]++;
		if (map_word[c] > map_board[c]) return false;
	}

	unordered_set<size_t> visited;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == word.front())
			{
				if (exist(board, i, j, word, visited)) return true;
			}
		}
	}
	return false;
}
```

我一开始是从后往前匹配的，就遇到了两个坑用例，超时了。  
发现改成从前往后的顺序，就过了。  

用例1：  
矩阵，[[a,a,a,a],[a,a,a,a],[a,a,a,a],[a,a,a,a],[a,a,a,b]
字符串，aaaaaaaaaaaaaaaaaaaa  
就是矩阵是19个a，1个b。字符串是20个a。  

用例2：  
矩阵，30 * 30的a，其中右下角最后一个字符不是a而是b。  
字符串，baaaa…………  一个b和899个a。  
这个用例从前向后比较好找，会从b开始，但是从后往前，会在一堆a里迷失。  
我后来从```word.pop_back()```，改成```word = word.substr(1, word.size() - 1)```就过了。  
感觉很欺负人了。  


### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)