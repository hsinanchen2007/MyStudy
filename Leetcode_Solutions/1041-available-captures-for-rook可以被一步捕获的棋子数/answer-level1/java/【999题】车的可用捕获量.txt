**方法一：循环探索**
```
class Solution {
    /**
    * 思路：
    * (1) 遍历找到棋盘中"白车R"的位置。
    * (2) 分别探索"白车R"上下左右四个方向。
    */
    public int numRookCaptures(char[][] board) {
        int ans = 0;
        // 配合遍历"白车R"的四个方向。
        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                // 找到"白车R"的位置。
                if(board[i][j] == 'R'){
                    // 遍历"白车R"的四个方向。
                    for(int k = 0; k < 4; k++){
                        // 每个方向遍历前"白车R"的初始位置。
                        int m = i, n = j;
                        // 循环探索每个方向，直到捕获黑色的卒或者无法继续探索。
                        for (;;){
                            m += dx[k];
                            n += dy[k];
                            // 如果在一个方向上越界或者遇到白色的象，则停止探索跳出循环。
                            if (m < 0 || m > 7 || n < 0 || n > 7 || board[m][n] == 'B'){
                                break;
                            }
                            // 如果捕获黑色的卒，则跳出循环停止探索。
                            if(board[m][n] == 'p'){
                                ans++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
}
```
