# 用时0ms 内存消耗39.2MB 双100%

就直接转接好了，用位运算来存数字，时间就是o(n),每个位置存上该放的值就好
每转一下就处理4个数字，所以最多需要转n*n/4次
因为每次转处理的都是同一圈的数字，所以如果一层处理完还没有处理完所有的数字就证明它有很多层修改循环条件再去处理里面的层就好了。

public void rotate(int[][] matrix) {
        int n = matrix.length;
        if(matrix==null||n==0) return;
        int k = 0,temp;
        int starti = 0,startj = 0;
        int tempj,tempi;
        while (k < ((n*n)/4)){
            tempi = starti;
            for (int j =startj ;j<n-1-startj;j++){
                temp = j;
                for (int c =0;c<3;c++){
                    tempj = n-1-tempi;
                    tempi = j;
                    matrix[starti][temp] = matrix[tempi][tempj]^matrix[starti][temp];
                    matrix[tempi][tempj] = matrix[tempi][tempj]^matrix[starti][temp];
                    matrix[starti][temp] = matrix[tempi][tempj]^matrix[starti][temp];
                    j = tempj;
                }
                j = temp;
                tempi = starti;
                k++;
            }
            starti++;
            startj++;
        }
    }