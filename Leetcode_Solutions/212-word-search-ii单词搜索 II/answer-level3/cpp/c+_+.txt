### 解题思路
trie+dfs

### 代码c+_+

```cpp
class Solution {
public:

    vector<vector<int> > trie;//构建trie树
    vector<int> cnt;//标记trie树字符串数组
    vector<string> ans;//返回的答案
    int idx;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
    vector<vector<bool>> flag;//标记是否已经用过当前单元格

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.size() == 0) return ans;
        trie = vector<vector<int>>(words.size()*30, vector<int>(26, 0));
        cnt = vector<int>(words.size()*30);
        flag = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        idx = 0;
        for(auto t : words) insert(t);//build trie

        for(int i = 0;i < board.size();++i)
            for(int j = 0;j < board[0].size();++j){
                string cur = "";
                cur += board[i][j];
                flag[i][j] = true;
                dfs(board, i, j, cur);
                flag[i][j] = false;
            }
        return ans;
    }

    void insert(string s){
        int p = 0;
        for(auto c : s){
            int t = c - 'a';
            if(trie[p][t] == 0) trie[p][t] = ++idx;
            p = trie[p][t];
        }
        cnt[p]++;
    }

    bool search(string s){
        int p = 0;
        for(auto c : s){
            int t = c - 'a';
            if(trie[p][t] == 0)return false;
            p = trie[p][t];
        }
        if(cnt[p]) {
            cnt[p] = 0;//这里因为如果已经找到了，下一次不会再找到重复的了
            return true;
        }
        else return false;
    }

    bool ispre(string s){
        int p = 0;
        for(auto c : s){
            int t = c - 'a';
            if(trie[p][t] == 0)return false;
            p = trie[p][t];
        }
        return true;
    }

    void dfs(vector<vector<char>>& board, int i, int j, string& cur){
        if(search(cur)) {
            ans.push_back(cur);
        }
        if(!ispre(cur)) return;
        for(int m = 0;m < 4;++m){
            int x = i + dx[m], y = j + dy[m];
            if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size()){
                if(!flag[x][y]){
                    flag[x][y] = true;
                    cur += board[x][y];
                    dfs(board, x, y, cur);
                    flag[x][y] = false;
                    cur = cur.substr(0, cur.size()-1);
                }
            }
        }
        return;
    }
};
```