    public int numRookCaptures(char[][] board) {
        int length = board.length;
        int num = 0;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                // 先找到白色的车
                if (board[i][j] == 'R') {
                    // 向上移动
                    int temp_i = i;
                    // 棋盘的边缘
                    for (; temp_i > 0; temp_i--) {
                        // 选择停止 ignore
                        // 遇到白色的象
                        if (board[temp_i][j] == 'B') {
                            break;
                        }
                        if (board[temp_i][j] == 'p') {
                            num++;
                            break;
                        }
                    }
                    // 向下移动
                    temp_i = i;
                    // 棋盘的边缘
                    for (; temp_i < length; temp_i++) {
                        // 选择停止 ignore
                        // 遇到白色的象
                        if (board[temp_i][j] == 'B') {
                            break;
                        }
                        if (board[temp_i][j] == 'p') {
                            num++;
                            break;
                        }
                    }

                    // 向左移动
                    int temp_j = j;
                    // 棋盘的边缘
                    for (; temp_j > 0; temp_j--) {
                        // 选择停止 ignore
                        // 遇到白色的象
                        if (board[i][temp_j] == 'B') {
                            break;
                        }
                        if (board[i][temp_j] == 'p') {
                            num++;
                            break;
                        }
                    }

                    // 向右移动
                    temp_j = j;
                    // 棋盘的边缘
                    for (; temp_j < length; temp_j++) {
                        // 选择停止 ignore
                        // 遇到白色的象
                        if (board[i][temp_j] == 'B') {
                            break;
                        }
                        if (board[i][temp_j] == 'p') {
                            num++;
                            break;
                        }
                    }
                }
            }
        }
        return num;
    }