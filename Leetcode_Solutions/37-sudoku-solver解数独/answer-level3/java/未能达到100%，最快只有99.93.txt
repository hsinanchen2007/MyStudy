* 1. 深度优先。借鉴签名valid sudoku的方法。
 * 2. 98.15，内存：78.15
 * 3. 这里要主要是这次的操作和循环前后的保持。
 * 4. 看了官方题解，最好的也就是这种方法。不过，叫回溯法。
 * 5. 还是： a. 递归结束条件。（这里就是全部遍历完，跳出循环，return true）； b.当下要做的操作。（这里就是判断1-9是否合适）；
 * c.递归前后状态的恢复。（这里只牵涉到三个数组的恢复）
 * 6. solveSudokuHelp3是最简单版本，也应该是最快的


```
/**
     * 1. 深度优先。借鉴签名valid sudoku的方法。
     * 2. 98.15，内存：78.15
     * 3. 这里要主要是这次的操作和循环前后的保持。
     * 4. 看了官方题解，最好的也就是这种方法。不过，叫回溯法。
     * 5. 还是： a. 递归结束条件。（这里就是全部遍历完，跳出循环，return true）； b.当下要做的操作。（这里就是判断1-9是否合适）；
     * c.递归前后状态的恢复。（这里只牵涉到三个数组的恢复）
     * 6. solveSudokuHelp3是最简单版本，也应该是最快的
     * 
     * 
     * @Author kaikai 2019年10月3日 下午2:40:07
     * @param board
     */
    public void solveSudoku(char[][] board) {
        int[] columns = new int[9];
        int[] rows = new int[9];
        int[] boxes = new int[9];
        int val;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                val = board[i][j] - '1';
                val = 1 << val;

                rows[i] += val;
                columns[j] += val;
                boxes[(i / 3) * 3 + j / 3] += val;
            }
        }
        // 这里假定一定有解
        solveSudokuHelp3(board, 0, 0, columns, rows, boxes);

    }

    public boolean solveSudokuHelp(char[][] board, int row, int column, int[] columns, int[] rows, int[] boxes) {

        int val;
        int tempRow;
        int tempColumn;
        int tempBox;
        int boxIndex;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {
                    boxIndex = (i / 3) * 3 + j / 3;
                    tempRow = rows[i];
                    tempColumn = columns[j];
                    tempBox = boxes[boxIndex];

                    for (int k = 1; k <= 9; k++) {
                        val = 1 << (k - 1);
                        if (((rows[i] | columns[j] | boxes[boxIndex]) & val) > 0) {
                            continue;
                        }

                        board[i][j] = (char) (k + 48);
                        rows[i] += val;
                        columns[j] += val;
                        boxes[boxIndex] += val;

                        // 记录原来的值
                        if (solveSudokuHelp(board, i, j, columns, rows, boxes)) {
                            return true;
                        } else {
                            rows[i] = tempRow;
                            columns[j] = tempColumn;
                            boxes[boxIndex] = tempBox;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }

            }
        }
        return true;

    }

    /**
     * 1.时间： 99.93，内存：77.65
     * 2. 改进是把row用起来。
     */
    public boolean solveSudokuHelp2(char[][] board, int row, int column, int[] columns, int[] rows, int[] boxes) {

        int val;
        int boxIndex;

        for (int i = row; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {
                    boxIndex = (i / 3) * 3 + j / 3;

                    for (int k = 1; k <= 9; k++) {
                        val = 1 << (k - 1);
                        if (((rows[i] | columns[j] | boxes[boxIndex]) & val) > 0) {
                            continue;
                        }

                        board[i][j] = (char) (k + 48);
                        rows[i] += val;
                        columns[j] += val;
                        boxes[boxIndex] += val;

                        // 记录原来的值
                        if (solveSudokuHelp2(board, i, j, columns, rows, boxes)) {
                            return true;
                        }
                        rows[i] -= val;
                        columns[j] -= val;
                        boxes[boxIndex] -= val;
                        board[i][j] = '.';

                    }
                    return false;
                }

            }
        }
        return true;

    }

    /**
     * 1. 将每次开始改成上次的开始，但是时间没有提升。
     * 2. 时间上：99.43，77.08， 最好的是99.93，80.52，99.43，77.08
     * 3. 99.93,84.53
     * 
     * @Author kaikai 2019年10月3日 下午5:49:44
     * @param board
     * @param i
     * @param j
     * @param columns
     * @param rows
     * @param boxes
     * @return
     */
    public boolean solveSudokuHelp3(char[][] board, int i, int j, int[] columns, int[] rows, int[] boxes) {

        int val;
        int boxIndex;
        // 这里不从零开始。直接从之前开始
        while (i < 9) {
            while (j < 9) {
                if (board[i][j] == '.') {
                    boxIndex = (i / 3) * 3 + j / 3;

                    for (int k = 1; k <= 9; k++) {
                        val = 1 << (k - 1);
                        if (((rows[i] | columns[j] | boxes[boxIndex]) & val) > 0) {
                            continue;
                        }

                        rows[i] += val;
                        columns[j] += val;
                        boxes[boxIndex] += val;

                        // j+1
                        if (solveSudokuHelp3(board, i, j + 1, columns, rows, boxes)) {
                            // 这里成功之后再赋值，而不是递归之前赋值，递归之后还原
                            board[i][j] = (char) (k + 48);
                            return true;
                        }
                        rows[i] -= val;
                        columns[j] -= val;
                        boxes[boxIndex] -= val;

                    }
                    return false;
                }
                j++;

            }
            i++;
            j = 0;
        }
        return true;

    }

    /**
     * 1. 尝试将这几个数组作为类字段。没有提升。
     */
    // final int[] columns = new int[9];
    // final int[] rows = new int[9];
    // final int[] boxes = new int[9];
    //
    // public void solveSudoku(char[][] board) {
    //
    // int val;
    // for (int i = 0; i < 9; i++) {
    // for (int j = 0; j < 9; j++) {
    // if (board[i][j] == '.') {
    // continue;
    // }
    // val = board[i][j] - '1';
    // val = 1 << val;
    //
    // rows[i] += val;
    // columns[j] += val;
    // boxes[(i / 3) * 3 + j / 3] += val;
    // }
    // }
    // // 这里假定一定有解
    // solveSudokuHelp4(board, 0, 0);
    //
    // }
    //
    // public boolean solveSudokuHelp4(char[][] board, int i, int j) {
    //
    // int val;
    // int boxIndex;
    // // 这里不从零开始。直接从之前开始
    // while (i < 9) {
    // while (j < 9) {
    // if (board[i][j] == '.') {
    // boxIndex = (i / 3) * 3 + j / 3;
    //
    // for (int k = 1; k <= 9; k++) {
    // val = 1 << (k - 1);
    // if (((rows[i] | columns[j] | boxes[boxIndex]) & val) > 0) {
    // continue;
    // }
    //
    // rows[i] += val;
    // columns[j] += val;
    // boxes[boxIndex] += val;
    //
    // // j+1
    // if (solveSudokuHelp4(board, i, j + 1)) {
    // // 这里成功之后再赋值，而不是递归之前赋值，递归之后还原
    // board[i][j] = (char) (k + 48);
    // return true;
    // }
    // rows[i] -= val;
    // columns[j] -= val;
    // boxes[boxIndex] -= val;
    //
    // }
    // return false;
    // }
    // j++;
    //
    // }
    // i++;
    // j = 0;
    // }
    // return true;
    //
    // }
```

