### 解题思路
1、利用BFS的思想，从上下左右、斜上下左右，八个位置搜索
2、在利用一个flag矩阵来记录每次是否改变过
3、根据规则来更新指

### 代码

```java
class Solution {
    public static void gameOfLife(int[][] board) {
        // bfs
        // 下上右左 斜上、斜下、斜左、斜右、斜上
        int[] dx = {1,-1,0,0};
        int[] dy = {0,0,1,-1};
        int[] ox = {-1,-1,1,1};
        int[] oy = {-1,1,-1,1};
        int newX = 0, newY = 0, newOx = 0, newOy = 0;
        // 记录活着的细胞数
        int count = 0;
        int m = board.length;
        int n = board[0].length;
        // 指示是否更新过
        int[][] flag = new int[m][n];
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                count = 0;
                // 上下左右
                for (int k = 0; k < 4; k++){
                    newX = i + dx[k];
                    newY = j + dy[k];

                    if (newX < 0 || newX >= m || newY < 0 || newY >= n){
                        continue;
                    }
                    if ((flag[newX][newY] == 1 && board[newX][newY] == 0) || (flag[newX][newY] == 0 && board[newX][newY] == 1)){ // 由1变0  或没变
                        count++;
                    }
                }
                // 斜上下左右
                for (int h = 0; h < 4; h++){
                    newOx = i + ox[h];
                    newOy = j + oy[h];

                    if (newOx < 0 || newOx >= m || newOy < 0 || newOy >= n){
                        continue;
                    }
                    if ((flag[newOx][newOy] == 1 && board[newOx][newOy] == 0) || (flag[newOx][newOy] == 0 && board[newOx][newOy] == 1)){ // 由1变0  或没变
                        count++;
                    }
                }
                // 活细胞
                if (board[i][j] == 1){
                    if (count < 2 || count > 3){ //死亡
                        board[i][j] = 0;
                        flag[i][j] = 1;
                    }
                }else{
                    if (count == 3){  // 死的复活
                        board[i][j] = 1;
                        flag[i][j] = 1;
                    }
                }
            }
        }
    }

}
```