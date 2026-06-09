### 解题思路
用比参数数组多两行两列的数组来记录每个位置的周围活细胞数，最后遍历计数数组的（1，1）~（board.length,board[i].length）根据规则改变原数组的细胞状态
### 代码

```java
class Solution {
        public void gameOfLife(int[][] board) {
        int[][] board_copy = new int[board.length+2][board[0].length+2]; //创建一个比原数组多两行两列的计数数组，用中间的board.length*board[i].length记录原数组周围活细胞数

        //遍历原数组，当是活细胞时，计数数组周围8个位置的计数+1；因为计数数组比原数组多上下左右四行，因此不用担心越界
        for(int i = 0;i<board.length;i++){
            for(int j = 0;j<board[i].length;j++){
                int i_copy = i+1;
                int j_copy = j+1;
                if(board[i][j]==1){
                    setCount(i_copy,j_copy,board_copy);
                }
            }
        }

        //遍历计数数组，根据规则改变原数组的细胞状态
        for(int i_copy = 1;i_copy<board_copy.length-1;i_copy++){
            for(int j_copy = 1;j_copy<board_copy[i_copy].length-1;j_copy++){
                int i = i_copy-1;
                int j = j_copy-1;

                //周围小于两个的不管当前什么状态都死
                //周围等于两个的细胞状态不变
                //周围等于三个的不管当前什么状态都活
                //周围大于三个的不管当前什么状态都死
                if(board_copy[i_copy][j_copy]<2||board_copy[i_copy][j_copy]>3){
                    board[i][j]=0;
                }
                else if(board_copy[i_copy][j_copy]==3){
                    board[i][j]=1;
                }
            }
        }
    }

    //周围8个位置计数+1
    public void setCount(int i, int j, int[][] board){
        board[i-1][j-1]+=1;
        board[i-1][j]+=1;
        board[i-1][j+1]+=1;
        board[i][j+1]+=1;
        board[i+1][j+1]+=1;
        board[i+1][j]+=1;
        board[i+1][j-1]+=1;
        board[i][j-1]+=1;
    }
}
```