使用前缀树将words存储，dfs遍历board。注意去重复。思路大同小异，做个记录。
```
class Solution {
    struct Trie{
        static const int SIZE = 26;
        bool isString;
        Trie *children[SIZE];
        Trie(){
            for(int i=0; i<SIZE; children[i++]=NULL);
            isString = false;
        }
        ~Trie(){
            for(int i=0; i<SIZE; ++i)
                if (children[i]) delete children[i];
        }
        void insert(string &word){
            Trie *node = this;
            for(const auto &ch:word){
                if (node->children[ch-'a']==NULL) node->children[ch-'a']=new Trie();
                node = node->children[ch-'a'];
            }
            node->isString = true;
        }
    };
    void dfs(vector<vector<char>>& board, int row, int col, string &str,
             Trie *node, vector<vector<bool> > &visit, vector<string> &ans){
        if (row<0 || row>=board.size() || col<0 || col>=board[0].size()
           || visit[row][col] || node==NULL) return;
        node=node->children[board[row][col]-'a'];
        if (node==NULL) return;
        str.push_back(board[row][col]);
        visit[row][col]=true;
        if (node->isString) {
            ans.push_back(str);
            node->isString=false;    // dulplication
        }
        static const int direct[][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(int i=0; i<4; ++i)
            dfs(board, row+direct[i][0], col+direct[i][1], str, node, visit, ans);
        str.pop_back();
        visit[row][col]=false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board[0].empty()) return {};
        Trie root;
        for(int i=0; i<words.size(); root.insert(words[i++]));
        int m=board.size(), n=board[0].size();
        vector<vector<bool> > visit(m, vector<bool>(n, false));
        vector<string> ans;
        string str;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                dfs(board, i, j, str, &root, visit, ans);
        return ans;
    }
};
```
