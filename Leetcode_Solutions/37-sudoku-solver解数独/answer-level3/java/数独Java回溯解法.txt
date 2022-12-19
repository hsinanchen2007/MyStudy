### 解题思路
* 如果使用暴力解法，找到所有空位的数字排列组合，性能将很差
* 我们使用回溯法，在每一次添加一个新数字时加上限制，可以大大减少迭代次数
* 限制为每一行，每一列，每一个数字块都不能出现重复的数字（0-9）
### 执行结果
执行用时 :7 ms, 在所有 Java 提交中击败了64.28%的用户
内存消耗 :37.1 MB, 在所有 Java 提交中击败了13.20%的用户
### 代码

```java
class Solution {
    private boolean[][] rowNumUsed = new boolean[9][9];
    private boolean[][] colNumUsed = new boolean[9][9];
    //cubeNumUsed为数字块的限制，其中cubeNum()方法计算数字块的编号
    private boolean[][] cubeNumUsed = new boolean[9][9];
    public void solveSudoku(char[][] board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                int num = board[i][j] - '1';
                rowNumUsed[i][num] = true;
                colNumUsed[j][num] = true;
                cubeNumUsed[cubeNum(i,j)][num] = true;
            }
        }
        backTrack(0, 0, board, rowNumUsed, colNumUsed, cubeNumUsed);
    }
    //回溯方法体，只有当整个数独解完后，才返回true
    private boolean backTrack(int i, int j, char[][] board,
    boolean[][] rowNumUsed, boolean[][] colNumUsed, boolean[][] cubeNumUsed){
        while(board[i][j] != '.'){
            if(++j == 9){
                i++;
                j = 0;
            }
            if(i == 9){
                return true;
            }
        }

        for(int num = 0; num < 9; num++){
            int cube = cubeNum(i,j);
            if(!rowNumUsed[i][num] && !colNumUsed[j][num] && !cubeNumUsed[cube][num]){
                board[i][j] = (char)(num + '1');
                rowNumUsed[i][num] = true;
                colNumUsed[j][num] = true;
                cubeNumUsed[cube][num] = true;
                //回溯
                if(backTrack(i, j, board, rowNumUsed, colNumUsed, cubeNumUsed)){
                    return true;
                }else{
                    rowNumUsed[i][num] = false;
                    colNumUsed[j][num] = false;
                    cubeNumUsed[cube][num] = false;
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }

    private int cubeNum(int i, int j){
        return 3*(i/3) + j/3;
    }
}
```