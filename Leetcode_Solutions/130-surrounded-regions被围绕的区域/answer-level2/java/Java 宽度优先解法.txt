从边界开始出发，找出由边界上的O所能延伸出去的所有O（岛），然后用markByBFS来将这些不能修改的位置做标记（T）
做完标记之后就很简单了，第一次遍历整个数组找O，所有的O都应该是X(内陆O)。然后再一次遍历整个数组，把T换回来，换成O。
```
class Coordinate {
    int x, y;
    public Coordinate(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {
    public void solve(char[][] board) {
        if(board == null || board.length < 1 || board[0].length < 1) return;
        for(int i = 0; i < board[0].length; i++){
            if(board[0][i] == 'O') markByBFS(board, 0, i);
        }
        // 第一列（第一个element除去）
        for(int i = 1; i < board.length; i++){
            if(board[i][0] == 'O') markByBFS(board, i, 0);
        }
        // 最后一行（第一个element除去）
        for(int i = 1; i < board[0].length; i++){
            if(board[board.length - 1][i] == 'O') markByBFS(board, board.length - 1, i);
        }
        // 最后一列（第一个、最后一个element除去
        for(int i = 1; i < board.length - 1; i++){
            if(board[i][board[0].length - 1] == 'O') markByBFS(board, i, board[0].length - 1);
        }
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    // MarkByBFS: 遍历到O都变成T,遇到X不变号
    private void markByBFS(char[][] board, int i, int j){
        int[] directionX = {0, 1, -1, 0};
        int[] directionY = {1, 0, 0, -1};
        Queue<Coordinate> queue = new LinkedList<>();
        queue.offer(new Coordinate(i, j));
        board[i][j] = 'T';
        while(!queue.isEmpty()){
            Coordinate coor = queue.poll();
            for (int a = 0; a < 4; a++) {
                Coordinate adj = new Coordinate(
                    coor.x + directionX[a],
                    coor.y + directionY[a]
                );
            if(!inBound(adj, board)) continue;
            if(board[adj.x][adj.y] == 'O'){
                board[adj.x][adj.y] = 'T';
                queue.offer(adj);
            }
        }
    }
}

    private boolean inBound(Coordinate coor, char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        return coor.x >= 0 && coor.x < n && coor.y >= 0 && coor.y < m;
    }
}
```
