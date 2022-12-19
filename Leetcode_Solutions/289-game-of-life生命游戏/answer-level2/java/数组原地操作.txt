# 解题思路
对于每个细胞，要根据原始细胞的状态判断，可以将细胞改变后的状态用其他字符代替，并且与原状态对应起来，这里选了2和3分别表示死细胞变活和活细胞变死，即2与0对应，3与1对应。

# 代码
```java
class Solution {
    public void gameOfLife(int[][] board) {
        int m = board.length;
        if(m == 0){
            return;
        }
        int n = board[0].length;
        int[][] dics = new int[][]{{-1, -1},{-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1}};
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                int cnt = 0;
                for(int[] dic : dics){
                    int x = i + dic[0];
                    int y = j + dic[1];
                    if(x >= 0 && y >= 0 && x < m && y < n && board[x][y] % 2 == 1){
                        cnt ++;
                    }
                }
                if(cnt == 3){
                    board[i][j] = board[i][j] == 0 ? 2 : 1; 
                }
                else if(cnt < 2 || cnt > 3){
                    board[i][j] = board[i][j] == 1 ? 3 : 0;
                }
            }
        }
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(board[i][j] == 2){
                    board[i][j] = 1;
                }
                if(board[i][j] == 3){
                    board[i][j] = 0;
                }
            }
        }
        return;
    }
}
```
