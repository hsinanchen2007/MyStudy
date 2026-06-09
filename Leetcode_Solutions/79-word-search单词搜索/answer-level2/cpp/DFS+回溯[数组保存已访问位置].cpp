解题思路：
1、采用额外空间存储访问标志位；
2、进行上下左右进行递归；
3、将已修改参数进行回溯；

```
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board.size() == 0) {
            return false;
        }
        if (word.empty() || word.size() == 0) {
            return false;
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word.front()) {
                    vector<vector<int>> grid = vector<vector<int>>(board.size(), vector<int>(board[0].size(), 0));
                    map<pair<int, int>, bool> memMap;
                    string str = "";
                    str = str + word.front();
                    if (Dfs(board, word, i, j, str, grid, memMap)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool Dfs(vector<vector<char>>& board, string word, int index1, int index2, string& curStr, vector<vector<int>>& grid, map<pair<int, int>, bool>& memMap) {
        if (curStr == word) {
            return true;
        }
        if (curStr.size() >= word.size()) {
            return false;
        }
        if (memMap.find(make_pair(index1, index2)) != memMap.end()) {
            return memMap[make_pair(index1, index2)];
        }
        int curIndex = curStr.size();
        bool flagUp = false;
        bool flagLeft = false;
        bool flagDown = false;
        bool flagRight = false;
        //up
        grid[index1][index2] = 1;
        curStr = curStr + word[curIndex];
        if (index1 - 1 >= 0 && word[curIndex] == board[index1 - 1][index2] && grid[index1 - 1][index2] == 0) {
            if (Dfs(board, word, index1 - 1, index2, curStr, grid, memMap)) {
                memMap[make_pair(index1, index2)] = true;
                return true;
            }
        }
        //left
        if (index2 - 1 >= 0 && word[curIndex] == board[index1][index2 - 1] && grid[index1][index2 - 1] == 0) {
            if (Dfs(board, word, index1, index2 - 1, curStr, grid, memMap)) {
                memMap[make_pair(index1, index2)] = true;
                return true;
            }
        }
        //down
        if (index1 + 1 < board.size() && word[curIndex] == board[index1 + 1][index2] && grid[index1 + 1][index2] == 0) {
            if (Dfs(board, word, index1 + 1, index2, curStr, grid, memMap)) {
                memMap[make_pair(index1, index2)] = true;
                return true;
            }
        }
        //right
        if (index2 + 1 < board[0].size() && word[curIndex] == board[index1][index2 + 1] && grid[index1][index2 + 1] == 0) {
            if (Dfs(board, word, index1, index2 + 1, curStr, grid, memMap)) {
                memMap[make_pair(index1, index2)] = true;
                return true;
            }
        }
        grid[index1][index2] = 0;
        curStr.erase(curStr.end() - 1);
        return false;
    }
};
```
