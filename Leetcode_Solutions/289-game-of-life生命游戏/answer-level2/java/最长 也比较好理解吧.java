### 解题思路
我写的好复杂啊~~~~
基本思想:
给每个做过判断的做个标记(例如 要活的+5 要死的 -5)

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {

        for (int i = 0; i < board.length; i++){
            for (int j = 0; j < board[0].length; j++){
                board[i][j] += doom(board,i,j);
                System.out.println(board[i][j]);
            }
        }

        for (int s = 0; s < board.length; s++){
            for (int t = 0; t < board[0].length; t++){
                if(board[s][t] == 5 || board[s][t] == 6){
                    board[s][t] = 1;
                } else {
                    board[s][t] = 0;
                }

            }
        }
    }

    public int doom(int[][] nums, int row, int col){
        int lifeNums = 0;

        for (int n = -1; n <= 1; n++){
            for (int m = -1; m <= 1; m++){

                if ((n == 0 && m == 0) ||row + n < 0 || row + n > nums.length - 1 || col + m < 0 || 
                    col + m > nums[0].length - 1){
                    continue;
                }

                if (nums[row + n][col + m] == 1 || nums[row + n][col + m] == 6 || nums[row + n][col + m] == -4){
                    lifeNums++;
                }        
            }
        }

        if (nums[row][col] == 1){
            if (lifeNums < 2 || lifeNums > 3){
                return -5;
            } else {
                return 5;
            }

        }

        if (nums[row][col] == 0){
            if (lifeNums == 3){
                return 5;
            }else {
                return -5;
            }
        }
        return -1000;
    }
}
```