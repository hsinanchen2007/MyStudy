### 解题思路
在DFS的同时遍历Trie树

### 代码

```c++ []
// Trie模板
class Node{
public:
    bool isWord = false;
    string word; // 加入存储单词节点
    Node *next[26];
};

class Trie{
public:
    Trie(){
        this->root = new Node();
    }

    void add(string& word){
        Node *cur = root;
        for(int i=0; i<word.size(); ++i){
            if(cur->next[word[i]-'a']==nullptr)
                cur->next[word[i]-'a'] = new Node();
            cur = cur->next[word[i]-'a'];
        }
        if(!cur->isWord){
            cur->isWord = true;
            cur->word = word;
        }
    }

    bool find(string& word){
        Node *cur = root;
        for(char ch : word){
            if(cur->next[ch-'a']==nullptr)
                return false;
            cur = cur->next[ch-'a'];
        }
        return cur->isWord;
    }

public:
    Node *root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // DFS+Trie优化
        vector<string> res;
        R = board.size();
        if(R == 0)
            return res;
        C = board[0].size();
        if(C == 0)
            return res;

        Trie *T = new Trie();
        for(string &word: words){
            T->add(word);
        }

        vis = vector<vector<bool>>(R, vector<bool>(C, false));
        
        // DFS
        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                Node *cur = T->root;
                if(cur->next[board[i][j]-'a']!=nullptr)
                    dfs(board, i, j, cur->next[board[i][j]-'a'], res);
            }
        }

        return res;
    }

private:
    void dfs(const vector<vector<char>>& B, int x, int y, Node *cur, vector<string>& res){
        if(cur->isWord){
            if(count(res.begin(), res.end(), cur->word)==0)
                res.push_back(cur->word);
        }
        vis[x][y] = true;
        for(auto &d: dirs){
            int nx = x+d[0];
            int ny = y+d[1];
            if(inArea(nx, ny) && !vis[nx][ny] && cur->next[B[nx][ny]-'a']!=nullptr){
                dfs(B, nx, ny, cur->next[B[nx][ny]-'a'], res);
            }
        }
        vis[x][y] = false;
    }

private:
    int R, C;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> vis;

private:
    bool inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }
};
```
```java []
class Solution {
    // Trie + DFS
    public List<String> findWords(char[][] board, String[] words) {
        this.res = new LinkedList<>();
        R = board.length;
        if(R == 0)
            return res;
            
        C = board[0].length;
        if(C == 0)
            return res;

        vis = new boolean[R][C];
        Trie T = new Trie();
        for(String word: words){
            T.add(word);
        }

        Node cur = T.root;

        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                if(cur.next.containsKey(board[i][j]))
                    dfs(board, i, j, cur.next.get(board[i][j]));
            }
        }

        return res;
    }

    private void dfs(char [][]B, int x, int y, Node cur){
        if(cur.isWord){
            if(!res.contains(cur.word))
                res.add(cur.word);
        }
        vis[x][y] = true;
        for(int []d: dirs){
            int nx = x+d[0];
            int ny = y+d[1];
            if(inArea(nx, ny) && !vis[nx][ny] &&cur.next.containsKey(B[nx][ny])){
                dfs(B, nx, ny, cur.next.get(B[nx][ny]));
            }
        }
        // 回溯
        vis[x][y] = false;
    }

    private boolean [][]vis;
    private List<String> res; 
    private boolean inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }
    private int R, C;
    private int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


    // Trie模板
    private class Node{
        boolean isWord;
        String word;
        HashMap<Character, Node> next;
        Node(){
            this.isWord = false;
            this.next = new HashMap<>();
            this.word = new String();
        }
    }

    private class Trie{
        Node root;
        Trie(){
            this.root = new Node();
        }

        void add(String word){
            Node cur = root;
            for(int i=0; i<word.length(); ++i){
                char ch = word.charAt(i);
                if(!cur.next.containsKey(ch))
                    cur.next.put(ch, new Node());
                cur = cur.next.get(ch);
            }
            if(!cur.isWord){
                cur.word = word;
                cur.isWord = true;
            }
        }
    }
}
```
```python []
# Trie模板
class Node:
    def __init__(self):
        self.isWord = False
        self.word = None
        self.next = dict()

class Trie:
    def __init__(self):
        self.root = Node()

    def add(self, word):
        cur = self.root
        for w in word:
            if w not in cur.next.keys():
                cur.next[w] = Node()
            cur = cur.next[w]
        if cur.isWord is False:
            cur.isWord = True # 标示当前节点是一个单词
            cur.word = word # 存储当前单词


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # Trie & DFS
        self.res = []
        self.R = len(board)
        self.C = len(board[0])
        self.vis = [[False for _ in range(self.C)] for _ in range(self.R)]
        self.dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]

        T = Trie()
        cur = T.root
        for word in words:
            T.add(word)
        for i in range(self.R):
            for j in range(self.C):
                if board[i][j] in cur.next.keys():
                    self.dfs(board, i, j, cur.next[board[i][j]])
        return self.res

    def dfs(self, B, x, y, cur):
        if cur.isWord is True:
            if cur.word not in self.res:
                self.res.append(cur.word)

        self.vis[x][y] = True
        for d in self.dirs:
            nx, ny = x+d[0], y+d[1]
            if self.inArea(nx, ny) and self.vis[nx][ny] is False and B[nx][ny] in cur.next.keys():
                self.dfs(B, nx, ny, cur.next[B[nx][ny]])
        self.vis[x][y] = False

    def inArea(self, x, y):
        return 0<= x and x<self.R and 0<=y and y<self.C
```