## 思路一：暴力递归（超时）
参考：[79. 单词搜索](https://leetcode-cn.com/problems/word-search/solution/79-dan-ci-sou-suo-ji-bai-9403hui-su-by-guohaoding/)

### 代码
```c++
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty()) {
            return {""};
        }        
        unordered_set<string> ures;
        unordered_set<string> uset(words.begin(), words.end());
        for (string word : words) {
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[0].size(); ++j) {
                    if (dfs(board, word, 0, i, j)) {
                        ures.insert(word);
                    }
                }
            }
        }
        vector<string> res(ures.begin(), ures.end()); 
        return res;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int depth, int row, int col) {
        int rows = board.size(), cols = board[0].size();
        if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word[depth]) {
            return false;
        }
        //遍历完
        if (depth == word.size() - 1) {
            return true;
        }
        char ch = board[row][col];
        board[row][col] = '#';
        bool found = dfs(board, word, depth + 1, row + 1, col) ||
                     dfs(board, word, depth + 1, row - 1, col) ||
                     dfs(board, word, depth + 1, row, col + 1) ||
                     dfs(board, word, depth + 1, row, col - 1);
        board[row][col] = ch;
        return found;
    }
};
```

## 思路二：Trie树
参考大佬代码：[212. 单词搜索II](https://leetcode.com/problems/word-search-ii/discuss/262396/C%2B%2B-Trie-solution-99.62-faster.)
### 代码
```c++
class Solution {
    struct TrieNode {
        vector<TrieNode*> children;
        string word;
        TrieNode() : children(vector<TrieNode*>(26, nullptr)), word("") {}
    };

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        TrieNode *root = buildTrie(words);
        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

    /** Inserts a word into the trie. */
    TrieNode *buildTrie(vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (string word : words) {            
            TrieNode *curr = root;
            for (char ch : word) {
                int i = ch - 'a';
                if (curr->children[i] == nullptr) {
                    curr->children[i] = new TrieNode();
                }
                curr = curr->children[i];
            }
            curr->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &result) {
        char c = board[i][j];
        if (c == '#' || p->children[c - 'a'] == nullptr) {
            return;    
        } 
        p = p->children[c - 'a'];
        if (p->word.size() > 0) {
            result.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '#';
        if (i > 0) {
            dfs(board, i - 1, j, p, result);    
        } 
        if (j > 0) {
            dfs(board, i, j - 1, p, result);    
        } 
        if (i < board.size() - 1) {
            dfs(board, i + 1, j, p, result);    
        } 
        if (j < board[0].size() - 1) {
            dfs(board, i, j + 1, p, result);    
        } 
        board[i][j] = c;
    }
};
```


