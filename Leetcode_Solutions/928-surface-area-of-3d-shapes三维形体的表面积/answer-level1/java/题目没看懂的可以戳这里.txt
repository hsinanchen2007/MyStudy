```
//示例[[2]] 隐含一个所给grid边长为1的条件，即在一个1*1的grid里放一2个1*1*1的正方体
//示例[[1,2],[3,4]] 隐含grid为2*2的规格，即在[0,0]放置1个正方体，[0,1]2个，[1,0]3个，[1,1]4个

//题外话
//说一个可能会考虑的似乎不太好的方向，直接分别考虑前后左右上下的表面积
//前后用2 乘 每一列最大值，左右用2 乘 每行最大值，上下 2 乘 所有不为0个数
//但是遇到类似中间镂空部分如示例3就过不了了
class Solution {
    public int surfaceArea(int[][] grid) {
        int N = grid.length;
        int count = 0;
        for(int row=0;row<N;row++){
            for(int col=0;col<N;col++){
                if(grid[row][col] != 0){
                    count += (2 + 4*grid[row][col]);//不考虑衔接重复的方格
                }
                //只考虑向下和向右两个方向方便且不需考虑重复
                if(col <= N-2){//最后一列就不用比较后一列
                    count -= 2 * Math.min(grid[row][col],grid[row][col+1]);
                    //去除前后衔接重复的方格
                }
                if(row <= N-2){//最后一行不用比较后一行
                    count -=  2 * Math.min(grid[row][col],grid[row+1][col]);
                    //去除左右衔接重复的方格
                }
            }
        }
        return count;
    }
}
```
