    public static int surfaceArea(int[][] grid) {

        //上面积==下面积
        //左面积==右面积
        //前面积==后面积
        int bottomTopArea=0;
        int leftArea=0;
        int frontArea=0;
        int n = grid.length;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                //计算上下面积
                if (grid[i][j]!=0){
                    //上下面积各+1
                    bottomTopArea+=2;
                }
                //计算前后面积
                if (j-1>=0){
                    if (grid[i][j-1]<=0){
                        //前后方格是空开的
                        frontArea+=grid[i][j];
                    }else{
                        //前后方格是紧挨在一起的如果后面的高度比前面高，则加面积，否则不做操作
                        if (grid[i][j]>grid[i][j-1]){
                            frontArea+=(grid[i][j]-grid[i][j-1]);
                        }
                    }
                }else{
                    frontArea+=grid[i][j];
                }

                //计算左右面积
                if (i-1>=0){
                    if (grid[i-1][j]<=0){
                        //左右方格是空开的
                        leftArea+=grid[i][j];
                    }else{
                        //左右是紧挨在一起的如果右面的高度比左高，则加面积，否则不做操作
                        if (grid[i][j]>grid[i-1][j]){
                            leftArea+=(grid[i][j]-grid[i-1][j]);
                        }
                    }
                }else{
                    leftArea+=grid[i][j];
                }

            }
        }
        return bottomTopArea+leftArea*2+frontArea*2;
    }