保留和边界‘O’连通的‘O’，其他都设置’X‘
```
  int[] dx = new int[]{-1,0,1,0};
        int[] dy = new int[]{0,1,0,-1};
        public void solve(char[][] board) {
            if (board.length <= 1 ) {
                return;
            }
            char[][] nboard = new char[board.length][];
            int[][] map = new int[board.length][];
            for (int i = 0; i < nboard.length;i++) {
                nboard[i] = Arrays.copyOfRange(board[i],0,board[i].length);
                map[i] = new int[board[i].length];
                Arrays.fill(board[i],'X');
                Arrays.fill(map[i],0);
            }

            for (int i = 0;i < nboard.length;i++) {
                for (int j = 0;j < nboard[i].length;j++) {
                    if (nboard[i][j] == 'O' && (i == 0 || j == 0 || i == board.length -1 || j == board[i].length - 1)) {
                        dfs(nboard,board,map,i,j);
                    }
                }
            }
            for (int i = 0;i < board.length;i++) {
                System.out.println(Arrays.toString(board[i]));
            }
        }

        private void dfs(char[][] board,char[][]nboard,int[][] map, int x, int y) {

            if (x < 0 || y < 0 ||  x >= board.length || y >= board[x].length) {
                return;
            }

            if (board[x][y] == 'X') {
                return;
            }
            map[x][y] = 1;
            nboard[x][y] = 'O';

            for (int i = 0; i < 4;i++) {
                int ddx = x + dx[i];
                int ddy = y + dy[i];
                if (ddy > 0 && ddx > 0 && ddy < board[x].length - 1 && ddx < board.length -1 && board[ddx][ddy] == 'O' && map[ddx][ddy] != 1) {
                   dfs(board,nboard,map,ddx,ddy);
                }
            }
        }
```
