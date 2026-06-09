 int len=grid.length;
        int i,j,sum=0;
        for(i=0;i<len;i++){
            for(j=0;j<len;j++){
                sum+=grid[i][j];//计算立方体个数
            }
        }
        sum*=6;//计算立方体所有的面
        for(j=0;j<len;j++){
            for(i=1;i<len;i++){
                sum-=Math.min(grid[i][j],grid[i-1][j])*2; //减去左右方向重叠的两个面
            }
        }
        for(i=0;i<len;i++){
            for(j=1;j<len;j++){
                sum-=Math.min(grid[i][j],grid[i][j-1])*2;//减去前后方向重叠的两个面
            }
        }
         for(i=0;i<len;i++){
            for(j=0;j<len;j++){
                if(grid[i][j]>1){
                    sum-=(grid[i][j]-1)*2;//减去上下方向重叠的两个面
                } 
            }
        }  
        return sum;
