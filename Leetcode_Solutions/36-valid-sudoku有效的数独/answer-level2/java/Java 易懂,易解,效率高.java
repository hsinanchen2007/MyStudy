**1.题意是很好理解的,写循环的时候难免有点绕,可以将这种抽象的题实例化一下;
2.最好动手写一写循环,写一行两行就能ok了,无非就是检测行,列,九宫格三种情况;
3.具体实现过程：row数组：存储原数组borad的每一行数字到row数组的每一行上进行检测,col数组：存储board数组的每一列数字到col数组的每一行进行检测,block数组：存储原数组borad的每一个九宫格到block数组的每一行上进行检测;**
```
简述：board(行) → row(行),board(列) → col(行), board(九宫格)→ block(行);
```
**5.完结。**

        public boolean isValidSudoku(char[][] board) {
            // 记录某行，某位数字是否已经被摆放
            boolean[][] row = new boolean[9][9];
            // 记录某列，某位数字是否已经被摆放
            boolean[][] col = new boolean[9][9];
            // 记录某 3x3 宫格内，某位数字是否已经被摆放
            boolean[][] block = new boolean[9][9];
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] != '.') {
                        int num = board[i][j] - '1';
                        int blockIndex = i / 3 * 3 + j / 3;
                        if (row[i][num] || col[j][num] || block[blockIndex][num]) {
                            return false;
                        } else {
                            row[i][num] = true;
                            col[j][num] = true;
                            block[blockIndex][num] = true;
                        }
                    }
                }
            }
            return true;
        }