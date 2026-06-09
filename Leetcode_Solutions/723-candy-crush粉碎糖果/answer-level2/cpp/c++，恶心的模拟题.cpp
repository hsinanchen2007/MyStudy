先对同一行进行消除
```
for (int i = 0; i < m; ++i) {
    int left;
    for (int j = 0; j < n - 2; j = left) {
        left = j + 1;
        if (!board[i][left]) {
            continue;
        }
        while (left < n && board[i][left] == board[i][j]) {
            left++;
        }
        if (left - j > 2) {
            for (int k = j; k < left; ++k) {
                visited[i][k] = board[i][k];
                board[i][k] = 0;
            }
            flag = false;
        }
    }
}
```
再对同一列进行消除，注意使用visited数组记录已被行消除的数字
```
for (int j = 0; j < n; j++) {
    int down;
    for (int i = 0; i < m - 2; i = down) {
        int tmp = board[i][j];
        if (visited[i][j]) {
            tmp = visited[i][j];
        }
        down = i + 1;
        if (!tmp) {
            continue;
        }
        while (down < m) {
            if (visited[down][j] && visited[down][j] == 
                down++;
            } else if (!visited[down][j] && board[down][
                down++;
            } else {
                break;
            }
        }
        if (down - i > 2) {
            for (int k = i; k < down; ++k) {
                board[k][j] = 0;
            }
            flag = false;
        }
    }
}
```
最后下落
```
for (int j = 0; j < n; ++j) {
    int i = m - 1;
    int pos = m - 1;
    while(i >= 0) {
        if (board[i][j]) {
            int tmp = board[i][j];
            board[i][j] = 0;
            board[pos--][j] = tmp;
        }
        i--;
    }
}
```
以上三个过程迭代执行，使用flag变量记录当前图是否为终态（即一次循环中未发生任何改变）  
完整代码如下：
```
vector<vector<int>> candyCrush(vector<vector<int>> &board) {
        int m = board.size();
        int n = board[0].size();
        int visited[m][n];
        bool flag;
        do {
            flag = true;
            memset(visited, 0, sizeof(visited));
            for (int i = 0; i < m; ++i) {
                int left;
                for (int j = 0; j < n - 2; j = left) {
                    left = j + 1;
                    if (!board[i][left]) {
                        continue;
                    }
                    while (left < n && board[i][left] == board[i][j]) {
                        left++;
                    }
                    if (left - j > 2) {
                        for (int k = j; k < left; ++k) {
                            visited[i][k] = board[i][k];
                            board[i][k] = 0;
                        }
                        flag = false;
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                int down;
                for (int i = 0; i < m - 2; i = down) {
                    int tmp = board[i][j];
                    if (visited[i][j]) {
                        tmp = visited[i][j];
                    }
                    down = i + 1;
                    if (!tmp) {
                        continue;
                    }
                    while (down < m) {
                        if (visited[down][j] && visited[down][j] == tmp) {
                            down++;
                        } else if (!visited[down][j] && board[down][j] == tmp) {
                            down++;
                        } else {
                            break;
                        }
                    }
                    if (down - i > 2) {
                        for (int k = i; k < down; ++k) {
                            board[k][j] = 0;
                        }
                        flag = false;
                    }
                }
            }
            for (int j = 0; j < n; ++j) {
                int i = m - 1;
                int pos = m - 1;
                while(i >= 0) {
                    if (board[i][j]) {
                        int tmp = board[i][j];
                        board[i][j] = 0;
                        board[pos--][j] = tmp;
                    }
                    i--;
                }
            }
        } while (!flag);
        return board;
    }
```