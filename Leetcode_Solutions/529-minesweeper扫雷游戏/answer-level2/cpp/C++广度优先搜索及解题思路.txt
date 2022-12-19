**题意如下：**
1. 点击地雷--显示X，返回；
2. 点空方块--若周围有地雷，显示数字n，返回；
3. 点空方块--若周围没有地雷，显示空白‘B’，并递归显示相连的’M‘方块；
4. 不需要考虑其余input；

**解题思路：**
1. 解题关键点在于处理所有相连的方块‘M‘，遍历所有相连'M',并将地雷附近的’M‘刷新成’数字‘，其余刷新成’B‘；
2. 由示例1可以看到，所有显示的白块’B‘必定相连，如果递归时遇到数字则不需处理，可以用反证法证明；
3. 选用广度优先搜索，不用纠结数字怎么显示。如果一个’M‘将要更新成数字n，则不再搜索其子节点；
4. **只需递归遍历得到的’B‘，必能遍历所有相连为’B‘的子节点；**


**关键代码：**
```
    ...
    访问某节点并统计其相邻的’M‘和’E‘的个数
    ...
    if (mineNum == 0) {
        board[pos[0]][pos[1]] = 'B';
        // 如果此点为’B‘，则自身必与click连通，遍历其为’B‘的子节点
        for (auto& val : arounds) {
            posQueue.push(val);
        }
    } else {
        // 如果此方块要显示为数字，则搜索停止，其余的方块交给队列里的‘B’去吧！
        board[pos[0]][pos[1]] = '0' + mineNum;
    }
```


**提交代码：**
```
class Solution {
   public:
    // 更新一个未显示过的‘M’，并处理周围方块
    void markAndQueue(const vector<int>& pos, queue<vector<int>>& posQueue,
        vector<vector<char>>& board, vector<vector<bool>>& visited)
    {
        int mineNum = 0;
        int bNum = 0;
        vector<vector<int>> arounds;
        for (int i = pos[0] - 1; i < pos[0] + 2; ++i) {
            if (i < 0 || i >= board.size()) {
                continue;
            }
            for (int j = pos[1] - 1; j < pos[1] + 2; ++j) {
                if (j < 0 || j >= board[0].size()) {
                    continue;
                }
                if (board[i][j] == 'M') {
                    mineNum++;
                } else if (board[i][j] == 'E' && !visited[i][j]) {
                    arounds.push_back(vector<int>{i, j});
                }
            }
        }
        // 如果此方块要显示为数字，则搜索停止
        if (mineNum == 0) {
            board[pos[0]][pos[1]] = 'B';
            for (auto& val : arounds) {
                posQueue.push(val);
            }
        } else {
            board[pos[0]][pos[1]] = '0' + mineNum;
        }
        visited[pos[0]][pos[1]] = true;
    }

    void updateEmptySquare(vector<vector<char>>& board, vector<int>& click)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        queue<vector<int>> posQueue;
        posQueue.push(click);
        while (!posQueue.empty()) {
            vector<int> pos = posQueue.front();
            posQueue.pop();
            // visit and book it
            if (!visited[pos[0]][pos[1]]) {
                markAndQueue(pos, posQueue, board, visited);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        // 0. 无需考虑input异常
        char& clickContent = board[click[0]][click[1]];
        // 1. 检查是否点到地雷
        if (board[click[0]][click[1]] == 'M') {
            clickContent = 'X';
            return board;
        }
        // 2. 更新所有”M“面板，包括计算地雷附近数字
        updateEmptySquare(board, click);
        return board;
    }
};
```

