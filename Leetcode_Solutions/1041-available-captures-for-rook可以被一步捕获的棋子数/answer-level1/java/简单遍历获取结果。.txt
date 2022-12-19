### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int count = 0, st = 0, ed = 0;
        for(int i = 0;i < board.length;i++){
            for(int j = 0;j < board[i].length;j++){
                if(board[i][j] == 'R'){
                    st = i;
                    ed = j;
                }
            }
        }

        int direct = 4;
        int[] dx = {1,0,-1,0};
        int[] dy = {0,1,0,-1};

        for(int d = 0; d < direct;d++){
            for(int step = 0; ;step++){
                int tx = st + step * dx[d];
                int ty = ed + step * dy[d];
                if(tx < 0 || tx >= board.length || ty < 0 || ty >= board.length || board[tx][ty] == 'B')
                    break;
                if( board[tx][ty] == 'p'){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}
```