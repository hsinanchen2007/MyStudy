### 解题思路
    

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int rows = board.length;
        int cols = board[0].length;
        int[] offsets = {0,1,-1};
        
        //遍历
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                int alives = 0; //周边8个元素存活的个数
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(!(offsets[i] == 0 && offsets[j] == 0)){
                            int r = row + offsets[i];
                            int c = col + offsets[j];
                        
                            if( (r<rows && r>=0) && (c<cols && c>=0) && (board[r][c] == 1 || board[r][c] == 2)){
                                alives ++ ;
                        }
                        }
                    }
                }

                if(board[row][col] == 1 && (alives < 2 ||  alives > 3)){
                    //1，3
                    board[row][col] = 2;
                }

                if(board[row][col] == 0 && alives == 3){
                    //4
                    board[row][col] = 3;
                }

            }
        }

        //遍历
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                board[row][col] = board[row][col]%2;
            }
        }

    }
}
```