//注：不是题解，纯粹自己的题记。
```
//相当于拿着树在做字符串的遍历，树的作用是在剪枝
class Solution {
public:
    struct TrieNode {
        string word;
        vector<TrieNode*> child;
        TrieNode() {
            word = "";
            child = vector<TrieNode*>(26, nullptr);
        }
    };

    struct Trie {
        TrieNode* root;
        void insert(string word) {
            TrieNode* cur = root;
            for(char c : word) {
                if(!cur->child[c - 'a']) {
                    cur->child[c - 'a'] = new TrieNode();
                }
                cur = cur->child[c - 'a'];
            }
            cur->word = word;
        }

        bool startWith(string word) {
            TrieNode* cur = root;
            for(char c : word) {
                if(!cur->child[c - 'a']) return false;
                cur = cur->child[c - 'a'];
            }
            return true;
        }

        Trie() {
            root = new TrieNode();
        }
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.size() == 0) return {};
        if(board.size() == 0 || board[0].size() == 0) return {};
        int rows = board.size();
        int cols = board[0].size();


        Trie* trie = new Trie();
        for(string word : words) {
            trie->insert(word);
        }

        set<string> re;
        for(int i = 0; i < rows; i++) 
            for(int j = 0; j < cols; j++) {
                dfs(board, i, j, trie->root, re);
            }
        vector<string> sv(re.begin(), re.end());
        return sv;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode* root, set<string>& re) {
        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || !root) return;
        char ch = board[i][j];
        if(ch == '#') return;
        if(root->child[ch - 'a'] == nullptr) return;
        if(root->child[ch - 'a']->word.size() > 0) {
            re.insert(root->child[ch - 'a']->word);
            //这里不能返回，因为当前的word可能还是其他word的前缀，比如ab aba
            //return;
        }
        board[i][j] = '#';
        dfs(board, i, j + 1, root->child[ch - 'a'], re);
        dfs(board, i, j - 1, root->child[ch - 'a'], re);
        dfs(board, i + 1, j, root->child[ch - 'a'], re);
        dfs(board, i - 1, j, root->child[ch - 'a'], re);
        board[i][j] = ch;
    }
};
```
