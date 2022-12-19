1.BFS搜索
2.找到一个玩朋友圈的
3.开始横纵感染
4.开始寻找下一个
```
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M)
    {
        int weChat = 0;
        for (int i = 0; i < M.size(); ++i) {
            for (int j = 0; j < M.at(i).size(); ++j) {
                const int weAreFriend = 1;
                if (M.at(i).at(j) == weAreFriend) {
                    ++weChat;
                    findCircleNumBfs(M, i, j);
                }
            }
        }
        return weChat;
    }
private:
    void findCircleNumBfs(vector<vector<int>>& M, int i, int j)
    {
        const int weAreFriend = 1;
        queue<pair<int, int>> checkQueue;
        checkQueue.push({i, j});
        M[i][j] = 0;
        while (!checkQueue.empty()) {
            pair<int, int> current = checkQueue.front();
            checkQueue.pop();
            scanCurrentRow(M, current, weAreFriend, checkQueue);
            scanCurrentCol(M, current, weAreFriend, checkQueue);
        }
    }

    void scanCurrentCol(vector<vector<int>> &M,
                        pair<int, int> &current,
                        const int weAreFriend,
                        queue<pair<int, int>> &checkQueue)
    {
        if (visitedCol.find(current.second) != visitedCol.end()) {
            return;
        }
        for (int row = 0; row < M.size(); ++row) {
            if (M.at(row).at(current.second) == weAreFriend) {
                checkQueue.push({ row, current.second});
                M[row][current.second] = 0;
            }
        }
        visitedCol.insert(current.second);
    }

    void scanCurrentRow(vector<vector<int>> &M,
                        pair<int, int> &current,
                        const int weAreFriend,
                        queue<pair<int, int>> &checkQueue)
    {
        if (visitedRow.find(current.first) != visitedRow.end()) {
            return;
        }
        for (int col = 0; col < M.at(current.first).size(); ++col) {
            if (M.at(current.first).at(col) == weAreFriend) {
                checkQueue.push({current.first, col});
                M[current.first][col] = 0;
            }
        }
        visitedRow.insert(current.first);
    }

private:
    set<int> visitedRow;
    set<int> visitedCol;
};
```
