******先上答案：
class Solution {
    private int[][] myrec = new int[50][50];
    public int surfaceArea(int[][] grid) {
        return calArea(grid,0,0);
    }

    public int calArea(int[][] grid,int i,int j){
        if(i<0||j<0||i>=grid.length||j>=grid[i].length||myrec[i][j]==1){
            return 0;
        }
        myrec[i][j]=1;
        int iArea = 0;
        if(grid[i][j]>0){
            iArea = grid[i][j]*4+2;
        }
        int chongdie = 0;   
        if(j+1<grid[i].length){
            iArea += calArea(grid,i,j+1);
            chongdie += Math.min(grid[i][j],grid[i][j+1])*2;
        }
        if(i+1<grid.length){
            iArea += calArea(grid,i+1,j);
            chongdie += Math.min(grid[i][j],grid[i+1][j])*2;
        }
        iArea -= chongdie;
        return iArea;
    }
}

首先需要计算叠加在一起的正方体的表面积是多少，可以看到1个正方体时表面积是6，2个正方体表面积是10，3个是14，4个是18，......依次类推，n个就是4n+2，当然n要是正整数哦。
然后我们从第一个方格，也就是(0,0)开始计算，如果第一个方格有正方体，它的下一个方向是向右或者向上，如果这些方格中也有正方体，则会有正方体的表面产生重叠，重叠的面积由正方体较少的方格决定，假设(0,0)有1个正方体，(0,1)有3个正方体，重叠的面积就是2......依次类推重叠的面积就是相邻方格中较少正方体的数量*2，在计算总面积的时候减去重叠的面积，就得到结果了。
最后，myrec数组的作用就是记录已经计算过的方格，避免重复计算。
第一次写题解，欢迎各位大佬批评指正～