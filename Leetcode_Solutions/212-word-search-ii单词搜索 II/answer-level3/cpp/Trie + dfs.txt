```
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = (int)board.size();
        if (m == 0) {
            return ret;
        }
        n = (int)board[0].size();
        G = board;
        // *mark = new int[m + 1];
        // for (int i = 0; i < m + 1; i++) {
        //     mark[i] = new int[n + 1];
        // }
        root = new Node();
        for (int i = 0; i < (int)words.size(); i++) {
            add(words[i]);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                memset(mark, 0, sizeof(mark));
                if (root->next[G[i][j] - 'a']) {
                    if (G[i][j] == 'e') {
                        cout << "okokokok" << endl;
                    }
                    string u = "";
                    u += G[i][j];
                    dfs(root->next[G[i][j] - 'a'], u, i, j);
                }
            }
        }
        return ret;
    }
private:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    struct Node {
        bool isWord;
        Node* next[26];
        Node() {
            isWord = false;
            for (int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
        }
    };
    Node* root;
    int m, n;
    int mark[111][111];
    vector<string> ret;
    vector<vector<char>> G;
    map<string, bool> mp;
    void add(string word) {
        Node* cur = root;
        for (int i = 0; i < (int)word.size(); i++) {
            int c = word[i] - 'a';
            if (cur->next[c] == NULL) {
                cur->next[c] = new Node();
            }
            cur = cur->next[c];
        }
        cur->isWord = true;
    }
    void dfs(Node* cur, string s, int x, int y) {
        mark[x][y] = 1;
        if (cur->isWord && !mp[s]) {
            mp[s] = true;
            ret.push_back(s);
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < m && yy >= 0 && yy < n && !mark[xx][yy]) {
               if (cur->next[G[xx][yy] - 'a']) {
                   dfs(cur->next[G[xx][yy] - 'a'], s + G[xx][yy], xx, yy);
                   mark[xx][yy] = 0;
               }
            }
        }
    }
};
```
