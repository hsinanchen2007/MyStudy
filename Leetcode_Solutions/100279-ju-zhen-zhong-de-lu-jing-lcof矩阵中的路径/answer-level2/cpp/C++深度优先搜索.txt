class Solution {
public:
	bool dfs(vector<vector<char>>& board, vector<vector<int>>&visit,int cur_i,int cur_j,string word,int word_index) {


		if (cur_i < 0 || cur_j < 0 || cur_i == board.size() || cur_j == board[0].size() || board[cur_i][cur_j] != word[word_index] || visit[cur_i][cur_j] == 1) {
			return false;
		}
		visit[cur_i][cur_j] = 1;
		word_index++;

		if (word_index == word.length())
			return true;

		int di[4] = { 0,0,1,-1 };
		int dj[4] = { -1,1,0,0 };
		for (int index = 0; index < 4; index++) {
			int next_i = cur_i + di[index], next_j = cur_j + dj[index];
			if (dfs(board, visit, next_i, next_j, word,word_index))
				return true;
		}

		//四个方向都找完了，还没找到，则返回false,并且重置当前节点为未访问
		visit[cur_i][cur_j] = 0; //将原先访问过的节点重新设置为0
		return false;
		 
	}
	bool exist(vector<vector<char>>& board, string word) {
		//1.在board中找到一个入口使得board[i][j] = word[0]
		//2.由于格子不能再次访问，所以新建一个visit数组用来辅助判断是否被访问过
		//3.接着再次找到下一个入口，再次开始
		vector<vector<int>>visit;
		vector<int>temp(board[0].size());
		visit.resize(board.size(), temp);
		bool found = false;
		for(int i =0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == word[0]) {
					if (dfs(board, visit, i, j, word,0))
						found = true;
				}
			}
		return found;
	}
};