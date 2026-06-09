
### 代码

```cpp
class Trie {
public:
    bool isEnd;
    Trie* next[26];
    
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next)); 
    }
    
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c-'a'] == NULL) {
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }
    
    Trie* search1(string word) {
        Trie* node = this;
        for (char c : word) {
            node = node->next[c - 'a'];
            if (node == NULL) {
                return NULL;
            }
        }
        return node->isEnd ? node : NULL;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            node = node->next[c-'a'];
            if (node == NULL) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<string> rs;
    void findWords_(vector<vector<char>>& board,Trie &trie,string word,int i,int j) {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#') return;
        word += board[i][j];
        
        //不存在前缀 提前结束
        if (!trie.startsWith(word)) return;

        char c = board[i][j];
        board[i][j] = '#';
        Trie *node = trie.search1(word);
        if (node && node->isEnd) {
            rs.emplace_back(word);
            node->isEnd = false;
        }
        findWords_(board, trie, word, i+1, j);
        findWords_(board, trie, word, i-1, j);
        findWords_(board, trie, word, i, j+1);
        findWords_(board, trie, word, i, j-1);
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size() == 0 || words.size() == 0) return {};
        Trie trie;
        for(string &word : words){
            trie.insert(word);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (rs.size() == words.size()) return rs;
                if ( trie.next[board[i][j] - 'a'] == NULL) continue;
                string word;
                findWords_(board, trie, word, i, j);
            }
        }
        return rs;
    }
};
```