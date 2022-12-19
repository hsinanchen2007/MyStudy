
bsf:
将2*3的表盘拉直为一位并用string表示，代表搜索的graph（通常是二维的双向图）
每层的搜索范围是棋盘中每个位置可以移动的数字（moves）
需要记录曾经搜索过的的字符串（visited）
队列q 包含每层潜在的搜索元素（tmp），需要注意的是队列的长度粗腰在开始搜索每层的时候显示计算，不能用q.size(),因为q的长度是动态变化的

class Solution {
public:
	int slidingPuzzle(vector<vector<int>>& board) {
		string tar = "123450";
		int depth = 0;
		vector<vector<int>> moves = {
			{1,3},
			{0,2,4},
			{1,5},
			{0,4},
			{1, 3, 5},
			{2,4},
		};

		string cur;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++)
				cur += board[i][j] + '0';
		}

		queue<string> q;
		unordered_set<string> visited = {cur};
		q.push(cur);
		
		for (int depth = 0; !q.empty(); depth++){// process (q)ueue per (d)epth
			uint32_t size = q.size(); // this step is must 
			for (int k = 0; k < size; k++) {
				string tmp = q.front();
				q.pop();
				if (tmp == tar) return depth;
				int zero = tmp.find('0');

				for (int next : moves[zero]) {
					string s = tmp;
					swap(s[zero], s[next]);
					if (visited.find(s) == visited.end()) {
						visited.insert(s);
						q.push(s);
					}
				}
			}
		}
		return -1;
	}
};