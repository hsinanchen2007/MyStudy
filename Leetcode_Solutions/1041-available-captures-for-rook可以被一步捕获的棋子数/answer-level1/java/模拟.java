### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int count = 0;
        a : for (int i=0; i<board.length; i++){
            for (int j=0; j<board[0].length; j++){
                if (board[i][j] == 'R'){
                    int[][] dirs = new int[][]{{1,0},{-1,0},{0,1},{0,-1}};
                    for (int[] dir : dirs){
                        int x = i;
                        int y = j;
                        while (x>=0 && y>=0 && y<=7 && x<=7 && board[x][y] != 'B'){
                            if (board[x][y] == 'p'){
                                count++;
                                break;
                            }
                            x += dir[0];
                            y += dir[1];
                        }
                    }
                    break a;
                }
            }
        }
        return count;
    }
}
```