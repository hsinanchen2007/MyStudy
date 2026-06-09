 
```java
  public void gameOfLife(int[][] board) {
 int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        int m = board.length;
        int n = board[0].length;
        int[][]copy = new int[m][n];

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                // 计算 live 细胞 count
                int count = 0;

                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || y < 0 || x >= board.length || y >= board[0].length) {
                        continue;
                    }
                    count += board[x][y] & 1;
                }
                if ((board[i][j] & 1) == 1) {
                    if (count == 2 || count == 3) {
                      //  board[i][j] = 0b11;
                        copy[i][j] = 1;
                    }
                } else if (count == 3) {
                   // board[i][j] = 0b10;
                    copy[i][j] = 1;
                }else {
                    copy[i][j] = 0;
                }
            }
        }

        for(int i = 0;i < board.length;i++)
            for(int j = 0;j < board[0].length;j++)
                board[i][j] = copy[i][j];

// 位运算操作 第二位保存信息，不改变第一位信息 因为还要继续循环遍历
//        for (int i = 0; i < board.length; i++) {
//            for (int j = 0; j < board[i].length; j++) {
//                board[i][j] = board[i][j] >> 1;
//            }
//        }

    }
```
       