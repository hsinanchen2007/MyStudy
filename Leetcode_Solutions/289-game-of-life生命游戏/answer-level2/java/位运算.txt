```java
class Solution {
    public void gameOfLife(int[][] board) {
        if(board.length == 0){
            return;
        }
        int[][] dir = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,1}, {1,-1}, {-1,-1}};
        int m = board.length;
        int n = board[0].length;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int alive = 0;
                for(int k = 0; k < 8; k++){
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if(x >= 0 && x < m && y >= 0 && y < n){
                        if((board[x][y] & 1) == 1 || (board[x][y] & 1) == 3)
                            alive++;
                        }
                    }
                //细胞初始状态 0 1 用二进制表示为 0000..00 0000..01
                //倒数第二位记为下一个状态
                //原来活细胞死亡，则 0000..01 = 1
                //原来活细胞活着，则 0000..11 = 3
                //原来死细胞复活，则 0000..10 = 2
                
                //判断细胞上一个状态，用位运算 &1
                // 0000..00 & 1 = 0 上一时刻死亡
                // 0000..01 & 1 = 1 上一时刻活着
                // 0000..01 & 1 = 1 上一时刻活着
                // 0000..11 & 1 = 3 上一时刻活着
                // 0000..10 & 1 = 2 上一时刻死亡
                
                //周围活细胞少于2，该位置活细胞死亡
                if(alive < 2){
                    if((board[i][j] & 1) == 1 || (board[i][j] & 1) == 3){
                        board[i][j] = 1;
                    }

                }
                //周围有两个或者三个活细胞，该位置活细胞依然存活
                if(alive ==2 || alive == 3){
                    if((board[i][j] & 1) == 1 || (board[i][j] & 1) == 3){
                        board[i][j] = 3;
                    }
                }
                //周围活细胞超过三个，该位置活细胞死亡
                if(alive > 3){
                    if((board[i][j] & 1) == 1 || (board[i][j] & 1) == 3){
                        board[i][j] = 1;
                    }
                }
                //周围活细胞等于三个，死细胞复活
                if(alive == 3){
                    if((board[i][j] & 1) == 0 || (board[i][j] & 1) == 2){
                        board[i][j] = 2;
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] >>= 1;
            }
        }
    }
}
```