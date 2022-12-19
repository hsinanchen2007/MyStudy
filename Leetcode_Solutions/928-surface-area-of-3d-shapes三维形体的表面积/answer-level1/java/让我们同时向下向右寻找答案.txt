### 解题思路
        //每个方块在不被挡住的情况下，有六面有效面积，值为6，则num_cubes*6
        //每一面被挡，表面积则减一,-num_cover
        //总式子为 num_cubes*6-num_cover

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        //首先判断N的大小
        int N=grid[0].length;
        //N等于1的情况
        if(N==1){
            if(grid[0][0]==1){
                return 6;
            }else{
                return grid[0][0]*4+2;
            }
        }
        //方块个数
        int num_cubes=0;
        //被挡住的面数
        int num_cover=0;
        //每个方块在不被挡住的情况下，有六面有效面积，值为6，则num_cubes*6
        //每一面被挡，表面积则减一,-num_cover
        //总式子为 num_cubes*6-num_cover

        //两层循环体遍历网格,主要寻找被挡的面数
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                num_cubes +=grid[i][j];
                //判断堆叠的被挡数
                if(grid[i][j]>1){
                    num_cover=num_cover+(grid[i][j]-1)*2;
                }
                //只判断下方和右方是否被挡
                if(i!=N-1){//只要不是最后一行
                    if(j!=N-1){//如果不是最后一列
                        //判断下方
                        int down=(grid[i][j]>=grid[i+1][j])?grid[i+1][j]:grid[i][j];
                        num_cover=num_cover+down*2;
                        //判断右方
                        int right=(grid[i][j]>=grid[i][j+1])?grid[i][j+1]:grid[i][j];
                        num_cover=num_cover+right*2;

                    }else{
                        //判断下方
                        int down=(grid[i][j]>=grid[i+1][j])?grid[i+1][j]:grid[i][j];
                        num_cover=num_cover+down*2;
                    }
                }else{//最后一行
                    //如果不是最后一个
                    if(j!=N-1){
                        //判断右方
                        int right=(grid[i][j]>=grid[i][j+1])?grid[i][j+1]:grid[i][j];
                        num_cover=num_cover+right*2;
                    }
                }

            }
        }
        return num_cubes*6-num_cover;
    }
}
