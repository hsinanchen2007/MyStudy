递归算法：
1.每次调用为网格中移动一个位置，只能走0所在的节点；
2.已经走过的位置用 3 标记，调用递归结束后，该节点重新改为 0；
3.用一个变量记录走过的 0 的次数（同样递归结束后变量减一）
4.不能再次移动时，判断是否所有 0 已经覆盖（即走过0的次数等于0的总数），并且下一步可以走到结束节点，若为是，则总数+1，若不是，则总数不变
代码：
`public int uniquePathsIII(int[][] grid) {
       int zeros = countZeros(grid);
       int[] onesPosition = getOnesPosition(grid);
        return count(grid, onesPosition[0], onesPosition[1], 0, 0, zeros);

    }

    /**
     * 找到网格中1的位置
     */
    private int[] getOnesPosition(int[][] grid){
        int[] result = new int[2];
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j ++){
                if(grid[i][j] == 1){
                    result[0] = i;
                    result[1] = j;
                }
            }
        }
        return result;
    }

    /**
     * 计算网格中0的数量
     * @param grid
     * @return
     */
    private int countZeros(int[][] grid){
        int count = 0;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j ++){
                if(grid[i][j] == 0){
                    count ++;
                }
            }
        }
        return count;
    }

    /**
     * 网格中移动
     */
    private int count(int[][] grid,int m, int n, int count, int currentZeros, int zeros){
        if(isFull(grid, m, n)){
            if(currentZeros == zeros && isEnd(grid, m, n)){
                count++;
                 return count;
            }
            else{
                return count;
            }
        }
        //上走一格
        if(m != 0){
            if(grid[m - 1][n] == 0){
                currentZeros ++;
                grid[m - 1][n] = 3;
                count = count(grid, m - 1, n, count, currentZeros, zeros);
                grid[m - 1][n] = 0;
                currentZeros --;
            }
        }
        //左走一格
        if(n != 0){
            if(grid[m][n - 1] == 0){
                currentZeros ++;
                grid[m][n - 1] = 3;
                count = count(grid, m, n - 1,count, currentZeros, zeros);
                grid[m][n - 1] = 0;
                currentZeros --;
            }
        }
        //下走一格
        if(m != grid.length - 1){
            if(grid[m + 1][n] == 0){
                currentZeros ++;
                grid[m + 1][n] = 3;
                count = count(grid, m + 1, n,count, currentZeros, zeros);
                grid[m + 1][n] = 0;
                currentZeros --;
            }
        }
        //右走一格
        if(n != grid[0].length - 1){
            if(grid[m][n + 1] == 0){
                currentZeros ++;
                grid[m][n + 1] = 3;
                count = count(grid, m, n + 1,count, currentZeros, zeros);
                grid[m][n + 1] = 0;
                currentZeros --;
            }
        }
        return count;
    }

    /**
     * 判断是否已经不能继续走
     * @param grid
     * @param m
     * @param n
     * @return
     */
    private boolean isFull(int[][] grid, int m, int n){
        if(m != 0 && grid[m - 1][n] == 0)
            return false;
        if(n != 0 && grid[m][n - 1] == 0)
            return false;
        if(m != grid.length - 1 && grid[m + 1][n] == 0)
            return false;
        if(n != grid[0].length - 1 && grid[m][n + 1] == 0)
            return false;
        return true;
    }

    /**
     * 判断是否相邻节点中有结束
     * @param grid
     * @param m
     * @param n
     * @return
     */
    private boolean isEnd(int[][] grid, int m, int n){
        if(m != 0 && grid[m - 1][n] == 2){
            return true;
        }
        if(n != 0 && grid[m][n - 1] == 2)
            return true;
        if(m != grid.length - 1 && grid[m + 1][n] == 2)
            return true;
        if(n != grid[0].length - 1 && grid[m][n + 1] == 2)
            return true;
        return false;
    }`