### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    int count;
    public int totalNQueens(int n) {

        int[] colums = new int[n];//记录已经放下的每一行的皇后的列数
        count = 0;
        backTracking(n, 0, colums);
        return count;
    }

    public void backTracking(int n, int raw, int[] colums) {
        if (raw == n) {
            count ++;
            return;
        }
        for (int col = 0; col < n; col ++) {
            colums[raw] = col;
            if (check(raw, col, colums)) {
                backTracking(n, raw + 1 , colums);
            }
            colums[raw] = -1;
        }
    }

    //检查当前输入是否有效
    private boolean check(int row, int col, int[] colums) {
       for (int i = 0; i < row; i++) {
           if (colums[i] == col || row - i == Math.abs( colums[i] - col))  { //当前这一列的正上方 和对角线没有皇后
               return false;
           }
       }
        return true;
    }
}
```