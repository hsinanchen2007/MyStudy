```
 public  void solve(char[][] board) {

        if (!(board == null || board.length == 0)) {

            //搜索数组
            int[] dx = {0, -1, 0, 1};
            int[] dy = {-1, 0, 1, 0};

            int n = board.length;
            int m = board[0].length;

            //访问数组
            int[][] book = new int[n][m];

            //bfs宽搜
            Queue<int[]> queue = new LinkedList<>();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == 0 || i == n-1||j==0||j==m-1) {
                        if (board[i][j] == 'O') {
                            //复合状态
                            board[i][j] = 'S';
                            queue.offer(new int[]{i, j});
                        }
                    }
                }

            }

            while (queue.size() != 0) {

                //队头出队
                int[] poll = queue.poll();
                int nowI = poll[0];
                int nowJ = poll[1];

                //bfs深搜
                for (int i = 0; i < 4; i++) {
                    int nextI = nowI + dx[i];
                    int nextJ = nowJ + dy[i];
                    if (nextI >= 0 && nextI <= n - 1 && nextJ >= 0 && nextJ <= m - 1 && book[nextI][nextJ] == 0) {
                        book[nextI][nextJ] = 1;
                        if (board[nextI][nextJ] == 'O') {
                            board[nextI][nextJ] = 'S';
                            queue.offer(new int[]{nextI, nextJ});
                        }
                    }

                }


            }

            //复合状态还原
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == 'O') board[i][j] = 'X';
                    if (board[i][j] == 'S') board[i][j] = 'O';

                }

            }


        }


    }
```
