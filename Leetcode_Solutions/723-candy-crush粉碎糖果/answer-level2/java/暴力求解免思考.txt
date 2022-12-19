无脑暴力求解
public class CandyCrush {
    private int xLength;
    private int yLength;
    private int[][] nowBoard;
    private List<int[]> needCancelList;

    public int[][] candyCrush(int[][] board) {
        if (board.length == 0) {
            return board;
        }
        xLength = board.length;
        yLength = board[0].length;
        nowBoard = board;
        needCancelList = new ArrayList<>();

        while (true) {
            for (int i = 0; i < xLength; i++) {
                for (int j = 0; j < yLength; j++) {
                    if (canBeCancel(i, j)) {
                        int[] newInt = new int[2];
                        newInt[0] = i;
                        newInt[1] = j;
                        needCancelList.add(newInt);
                    }
                }
            }
            if (needCancelList.size() == 0) {
                break;
            }
            deleteElement();
            refreshData();
            needCancelList = new ArrayList<>();
        }

        return board;
    }

    // 删除元素
    private void deleteElement() {
        for (int[] tempEle : needCancelList) {
            int x = tempEle[0];
            int y = tempEle[1];
            nowBoard[x][y] = 0;
        }
    }

    // 刷新数组
    private void refreshData() {
        for (int j = 0; j < yLength; j++) {
            for (int i = xLength - 1; i >= 0; i--) {
                if (nowBoard[i][j] == 0) {
                    int[] looked = lookForData(i, j);
                    if (looked != null) {
                        nowBoard[i][j] = nowBoard[looked[0]][looked[1]];
                        nowBoard[looked[0]][looked[1]] = 0;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    // 向上找要填充过来的数
    private int[] lookForData(int i, int j) {
        int[] result = new int[2];
        for (int x = i - 1; x >= 0; x--) {
            if(nowBoard[x][j] != 0){
                result[0] = x;
                result[1] = j;
                return result;
            }
        }
        return null;
    }

    // 判断一个位置要不要被消除
    private boolean canBeCancel(int x, int y) {
        if (nowBoard[x][y] == 0) {
            return false;
        }

        int value = nowBoard[x][y];
        if (isNotOutBorder(x - 2, y) && value == nowBoard[x - 2][y]
                && isNotOutBorder(x - 1, y) && value == nowBoard[x - 1][y]) {
            return true;
        }

        if (isNotOutBorder(x - 1, y) && value == nowBoard[x - 1][y]
                && isNotOutBorder(x + 1, y) && value == nowBoard[x + 1][y]) {
            return true;
        }

        if (isNotOutBorder(x + 1, y) && value == nowBoard[x + 1][y]
                && isNotOutBorder(x + 2, y) && value == nowBoard[x + 2][y]) {
            return true;
        }

        if (isNotOutBorder(x, y - 2) && value == nowBoard[x][y - 2]
                && isNotOutBorder(x, y - 1) && value == nowBoard[x][y - 1]) {
            return true;
        }

        if (isNotOutBorder(x, y - 1) && value == nowBoard[x][y - 1]
                && isNotOutBorder(x, y + 1) && value == nowBoard[x][y + 1]) {
            return true;
        }

        if (isNotOutBorder(x, y + 1) && value == nowBoard[x][y + 1]
                && isNotOutBorder(x, y + 2) && value == nowBoard[x][y + 2]) {
            return true;
        }

        return false;
    }


    // 判断是否越界
    private boolean isNotOutBorder(int x, int y) {
        return !(x < 0 || y < 0 || x > xLength - 1 || y > yLength - 1);
    }
}
