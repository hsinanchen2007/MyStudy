```
public class Solution{
    public static void main(String[] args) {
        char[][] board = {
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', 'p', '.', '.', '.', '.'},
                {'.', '.', '.', 'R', '.', '.', '.', 'p'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', 'p', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'}};

        int res = numRookCaptures(board);
        System.out.println(res);

    }

    public static int numRookCaptures(char[][] board) {
        int westP, eastP, northP, southP, totalP = 0;
        String[] directions = {"West", "East", "North", "South"};
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                //  标示4个方向，直接统计每条线上的小p
                if (board[i][j] == 'R') {
                    westP = countP(i, j - 1, directions[0], board);
                    eastP = countP(i, j + 1, directions[1], board);
                    northP = countP(i + 1, j, directions[2], board);
                    southP = countP(i - 1, j, directions[3], board);
                    totalP = westP + eastP + northP + southP;
                }
            }
        }
        return totalP;
    }

    //说实在，这块代码比较不优雅
    private static int countP(int x, int y, String direction, char[][] board) {
        int res = 0;
        switch (direction) {
            // 注意 上移，就是纵坐标不动，横坐标-1
            case "North":
                while (isValidArea(x)) {
                    if (board[x][y] == 'p' || board[x][y] == 'B') break;
                    x++;
                }
                res = (x < 8) && board[x][y] == 'p' ? 1 : 0;
                break;
            // 注意 下移，就是纵坐标不动，横坐标+1
            case "South":
                while (isValidArea(x)) {
                    if (board[x][y] == 'p'|| board[x][y] == 'B') break;
                    x--;
                }
                res = (x >= 0) && board[x][y] == 'p'? 1 : 0;
                break;
            // 注意 右移，就是横坐标不动，纵坐标+1
            case "East":
                while (isValidArea(y)) {
                    if (board[x][y] == 'p'|| board[x][y] == 'B') break;
                    y++;
                }
                res = (y < 8) && board[x][y] == 'p' ? 1 : 0;
                break;
            // 注意 左移，就是横坐标不动，纵坐标-1
            case "West":
                while (isValidArea(y)) {
                    if (board[x][y] == 'p'|| board[x][y] == 'B') break;
                    y--;
                }
                res = (y >= 0) && board[x][y] == 'p'? 1 : 0;
                break;
        }
        return res;
    }

    private static boolean isValidArea(int index) {
        return index >= 0 && index < 8;
    }

}
```
