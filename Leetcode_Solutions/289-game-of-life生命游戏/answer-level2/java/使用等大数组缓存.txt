### 解题思路
遍历，计数，缓存更新结果，输出更新结果

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int m = board.length;
        int n = board[0].length;
        int[][] next = new int[m][n];

        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                int count = 0;
                for(int ti = i - 1; ti < i + 2; ti++){
                    for(int tj = j - 1; tj < j + 2; tj++){
                        if(ti == i && tj == j)continue;
                        if(ti >= 0 && ti < m && tj >= 0 && tj < n){
                            count += board[ti][tj];
                        }
                    }
                }
                if(board[i][j] == 1){
                    if(count < 2 || count > 3){
                        next[i][j] = 0;
                    }else {
                        next[i][j] = 1;
                    }
                }else {
                    if(count == 3){
                        next[i][j] = 1;
                    }else {
                        next[i][j] = 0;
                    }
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = next[i][j];
            }
        }

        
    }
}
```