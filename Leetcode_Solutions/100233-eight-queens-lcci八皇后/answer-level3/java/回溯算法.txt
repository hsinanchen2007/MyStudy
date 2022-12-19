在`n*n`的棋盘上放置`n`个皇后，要求皇后之间不能攻击，显然每行只有一个皇后，每列只有一个皇后，而且任意两个皇后不能在同一条斜线上。
对于给定的`n`，创建一个`n`行`n`列的二维数组表示棋盘，该数组初始状态为空棋盘（所有元素都是`'.'`）。通过回溯的方法，依次在每一行放置一个皇后，要求新放置的皇后不能和任何已经放置的皇后有攻击。
回溯方法的参数包括棋盘数组、棋盘大小`n`、已经放置的皇后数。初始调用，棋盘数组为空棋盘，已经放置的皇后数为0。对于当前行，尝试在每一格放置皇后（将棋盘数组中的相应元素改成`'Q'`），如果新放置的皇后不会和已经放置的皇后产生攻击，则递归调用回溯方法，递归调用时的参数中，棋盘数组为更新后的状态，棋盘大小`n`不变，已经放置的皇后数为增加1之后的值。递归调用结束之后，将放置皇后的格恢复到空（将棋盘数组中的相应元素改回`'.'`）。若已经放置的皇后数等于`n`，则是回溯方法的基准情形，将当前的棋盘数组加入返回列表并返回。
通过回溯算法得到所有可能的解以后，对于每个解，将二维数组转化成字符串，并加入返回列表，最后返回。
```
class Solution {
    public List<List<String>> solveNQueens(int n) {
        char[][] emptyChessboard = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                emptyChessboard[i][j] = '.';
        }
        List<char[][]> chessboardList = backtrack(emptyChessboard, n, 0);
        List<List<String>> chessboardStrList = new ArrayList<List<String>>();
        for (char[][] chessboard : chessboardList) {
            List<String> chessboardStr = arrayToList(chessboard);
            chessboardStrList.add(chessboardStr);
        }
        return chessboardStrList;
    }

    public List<char[][]> backtrack(char[][] chessboard, int n, int count) {
        List<char[][]> list = new ArrayList<char[][]>();
        if (count == n) {
            char[][] curChessboard = new char[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    curChessboard[i][j] = chessboard[i][j];
            }
            list.add(curChessboard);
            return list;
        }
        for (int i = 0; i < n; i++) {
            if (isLegal(chessboard, count, i)) {
                chessboard[count][i] = 'Q';
                List<char[][]> curList = backtrack(chessboard, n, count + 1);
                list.addAll(curList);
                chessboard[count][i] = '.';
            }
        }
        return list;
    }

    public boolean isLegal(char[][] chessboard, int count, int index) {
        int n = chessboard.length;
        for (int i = count - 1; i >= 0; i--) {
            if (chessboard[i][index] == 'Q')
                return false;
        }
        for (int i = count - 1, j = index - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        for (int i = count - 1, j = index + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        return true;
    }

    public List<String> arrayToList(char[][] chessboard) {
        List<String> list = new ArrayList<String>();
        for (char[] row : chessboard)
            list.add(new String(row));
        return list;
    }
}
```
