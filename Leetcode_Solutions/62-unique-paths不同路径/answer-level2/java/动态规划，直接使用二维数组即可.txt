    public int uniquePaths(int m, int n) {
     // 动态规划算法  用二维数组存到每一个点的路径条数，
    // 变化的时候  将左边的与上面的相加即可
        
        int[][] number = new int[m+1][n+1];
        number[1][1] = 1;
        for( int i = 1; i <= m; i ++ ){
            for( int j= 1; j <= n ;j ++ ){
                if(i == 1 && j == 1){
                    number[i][j] = 1;
                }else{
                    number[i][j] = number[i-1][j] + number[i][j-1];
                }
            }
        }
        
        return number[m][n];
        
    }