```
class Trie {
public:
	unordered_map<char, Trie*> _dict;
	bool _end = false;
	Trie() {}
	void insert(string& word) {
		Trie* node = this;
		for (auto& c : word) {
			if (node->_dict.count(c) == 0) {
				node->_dict[c] = new Trie();
			}
			node = node->_dict[c];
		}
		node->_end = true;
	}

	void search(vector<vector<char>>& board, vector<string>& ans) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				recur(i, j, "", this, board, ans);
			}
		}
	}
	
	void recur(int i, int j, string selected_so_far, Trie* node, vector<vector<char>>& board, vector<string>& ans) {
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#') {
			return;
		}

		char cur = board[i][j];
		selected_so_far += cur;
		node = node->_dict[cur];
		if (node && node->_end) {
			ans.push_back(selected_so_far);
			node->_end = false;
		}

		vector<vector<int> > move = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
		board[i][j] = '#';
		if (node) {
			for (auto& delta : move) {
				recur(i + delta[0], j + delta[1], selected_so_far, node, board, ans);
			}
		}
		board[i][j] = cur;
	}
};
class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		Trie trie;
		for (auto&str : words) {
			trie.insert(str);
		}
		vector<string> ans;
		trie.search(board, ans);
		return ans;
	}

	// 	Trie trie;
	// 	vector<string> ans;
	// 	for (string& w : words) {
	// 		trie.insert(w);
	// 	}
	// 	trie.search(ans, board);
	// 	return ans;
	// }
};
```
