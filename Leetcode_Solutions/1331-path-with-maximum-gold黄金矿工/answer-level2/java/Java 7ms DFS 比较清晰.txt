为了减少空间利用率和时间（是我自己觉得会花费时间，但是我没有试过），我没有利用数组存储上下左右的移动，那样其实很方便的，而且代码长度也会变短，但是2*4的数组的存储和遍历也要时间呀哈哈哈哈，一点编程道德都没有
```java []
class Solution {
    private int row;
    private int col;
    private boolean outOfRage(int m, int n){
        return !(m >= 0 && m < row && n >= 0 && n < col);
    }
    private boolean isFull(int[][] grid, int m, int n){
        if(outOfRage(m,n)) return false;
        return grid[m][n] != 0;
    }
    //DFS
    private int getResult(int[][] grid, int m, int n){
        int res = grid[m][n];
        int temp = res;
        int curr = res;
        grid[m][n] = 0;
        if(isFull(grid, m - 1, n)){
            res = Math.max(res, temp + getResult(grid, m-1, n));
        }
        if(isFull(grid, m + 1, n)){
            res = Math.max(res, temp + getResult(grid, m+1, n));
        }
        if(isFull(grid, m, n - 1)){
            res = Math.max(res, temp + getResult(grid, m, n-1));
        }
        if(isFull(grid, m, n + 1)){
            res = Math.max(res, temp + getResult(grid, m, n+1));
        }
        grid[m][n] = curr;
        return res;
    }
    //这里参考8ms的方法，判断是否可以作为起始点
    private boolean asStart(int[][] grid, int m, int n){
        if(m == 0 && n == 0) return true;
        if(m == 0 && n == col-1) return true;
        if(m == row-1 && n == 0) return true;
        if(m == row-1 && n == col-1) return true;
        int neighbor = 0;
        if(isFull(grid, m - 1, n)) neighbor++;
        if(isFull(grid, m + 1, n)) neighbor++;
        if(isFull(grid, m, n - 1)) neighbor++;
        if(isFull(grid, m, n + 1)) neighbor++;

        return neighbor<2;
    }

    public int getMaximumGold(int[][] grid) {
        this.row = grid.length;
        this.col = grid[0].length;
        int maxRes = 0;
        for(int i = 0; i < grid.length; ++i){
            for(int j = 0; j < grid[0].length; ++j){
                if(grid[i][j] != 0&&asStart(grid, i, j)){
                    maxRes = Math.max(getResult(grid, i, j), maxRes);
                }
            }
        }
        return maxRes;
    }
}
```
