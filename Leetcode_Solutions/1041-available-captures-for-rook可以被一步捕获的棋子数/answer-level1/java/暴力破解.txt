题很简单
1. 找到车
2. 横竖遍历
3. 碰到白象、边界停止，碰到卒 result++
```
    public int numRookCaptures(char[][] board) {
        int top = 0;
        int bottom = 0;
        int left = 0;
        int right = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    int x = i;
                    int y = j;
                    //上
                    while (true) {
                        y++;
                        if (y >= 8 || board[x][y] == 'B') {
                            break;
                        } else {
                            if (board[x][y] == 'p') {
                                bottom++;
                                break;
                            }
                        }
                    }
                    y = j;
                    //下
                    while (true) {
                        y--;
                        if (y < 0 || board[x][y] == 'B') {
                            break;
                        } else {
                            if (board[x][y] == 'p') {
                                top++;
                                break;
                            }
                        }
                    }
                     y = j;
                    //左
                    while (true) {
                        x--;
                        if (x < 0 || board[x][y] == 'B') {
                            break;
                        } else {
                            if (board[x][y] == 'p') {
                                left++;
                                break;
                            }
                        }
                    }
                    x=i;
                    //右
                    while (true) {
                        x++;
                        if (x >= 8 || board[x][y] == 'B') {
                            break;
                        } else {
                            if (board[x][y] == 'p') {
                                right++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return top + bottom + left + right;
    }
```
