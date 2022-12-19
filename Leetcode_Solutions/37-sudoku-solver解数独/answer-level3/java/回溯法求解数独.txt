```
class Solution {
    int size = 9;
	int square = size * size;
	int emptyCount = 0;
	int[] xIndex = new int[square];
	int[] yIndex = new int[square];	
	boolean[][] columnUsed = new boolean[size][size];
	boolean[][] rowUsed = new boolean[size][size];
	boolean[][] boxUsed = new boolean[size][size];
	char[][] result = new char[size][size];
	boolean suduSolved = false;

    public void solveSudoku(char[][] board) {
        if (board.length != size) {
            return;
        }
        if (board[0].length != size) {
            return;
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == '.') {
                    xIndex[emptyCount] = i;
                    yIndex[emptyCount] = j;
                    emptyCount++;
                } else {
                    updateUsed(i, j, board[i][j] - '0' - 1, true);
                }
                result[i][j] = board[i][j];
            }
        }

        doShuDu(0);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                board[i][j] = result[i][j];
            }
        }
    }

    public void doShuDu(int step)
    {
        if (step == emptyCount) {
        	suduSolved = true;
            return;
        } else {
            int x = xIndex[step];
            int y = yIndex[step];
            for (int i = 0; i < size; i++) {
                if (!columnUsed[x][i] && !rowUsed[y][i] && !boxUsed[(x / 3) * 3 + y / 3][i]) {
                    result[x][y] = (char)(i + 1 + '0');
                    step++;
                    updateUsed(x, y, i, true);

                    doShuDu(step);

                    if (!suduSolved) {
                        result[x][y] = '.';
                        step--;
                        updateUsed(x, y, i, false);
                    }
                }
            }
        }
    }

    public void updateUsed(int x, int y, int index, boolean flag)
    {
        columnUsed[x][index] = flag;
        rowUsed[y][index] = flag;
        boxUsed[(x / 3) * 3 + y / 3][index] = flag;
    }
}
```
