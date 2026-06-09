```
class Solution {
public:
    struct TrieNode {
        bool flag;
        map<char, TrieNode*> next;
        TrieNode() : flag(false) {}
    };
    TrieNode* root;
    Solution() {
        root = new TrieNode();
    }
    int neighbors[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void initTrieTree(vector<string>& words) {
        TrieNode* node;
        for (auto w : words) {
            node = root;
            for (auto x : w) {
                if (node->next.count(x) == 0) {
                    node->next[x] = new TrieNode();
                }
                node = node->next[x];
            }
            node->flag = true;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        set<string> res_set;
        if (board.empty())
            return res;
        int R = board.size();
        int C = board[0].size();
        initTrieTree(words);
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        TrieNode* node = root;
        string word;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                fw(board, i, j, R, C, visited, node, word, res_set);
            }
        }
        res.resize(res_set.size());
        copy(res_set.begin(), res_set.end(), res.begin());
        return res;
    }
    void fw(vector<vector<char>>& board, int ix, int iy, int R, int C,
            vector<vector<bool>>& visited,
            TrieNode* node,
            string& word,
            set<string>& res) {
        if (node->flag) {
            res.insert(word);
        }
        if (board.empty() || ix < 0 || iy < 0 || ix >= R || iy >= C)
            return;
        if (visited[ix][iy])
            return;
        if (node->next.count(board[ix][iy]) == 0)
            return;
        node = node->next[board[ix][iy]];
        word += board[ix][iy];
        visited[ix][iy] = true;
        for (int i = 0; i < 4; ++i) {
            ix += neighbors[i][0];
            iy += neighbors[i][1];
            fw(board, ix, iy, R, C, visited, node, word, res);
            ix -= neighbors[i][0];
            iy -= neighbors[i][1];
        }
        word.pop_back();
        visited[ix][iy] = false;
    } 
};
```
