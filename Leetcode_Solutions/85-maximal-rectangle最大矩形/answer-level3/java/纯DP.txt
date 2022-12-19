思路:
把整个数组遍历一遍,找到以当前点为矩形右下角的最大面积,并且记录长和宽

如果当前点为0,必然不是矩形,该点对应的x,y,s都为0
如果当前点为1,则考虑(i-1,j)所对应的是否为矩形
    如果是,那么相当于在原来的矩形中续了一个单位的y(x的长度依赖于i-1,j这个矩形的x,并且要进行判断,看是否该行中,对应x长度的格子是否都为1,否则另算根据新的x长度算面积)。
    如果不是,那么相当于x长度为1,,y的长度要依次向上查找,,直到遇到0位置,面积就是(1*y的长度)
同理考虑(i,j-1)
都计算完了以后取两者面积最大值作为(i,j)所在的点的面积最大值

如果要优化的话,还可以不用辅助类,令起两个数组来存储长度和宽度,应该可以降一些空间复杂度

``` 
/*执行用时：6 ms内存消耗：42.8 MB*/
public class Solution {
    public static int maximalRectangle(char[][] matrix) {
        if (matrix.length==0||matrix[0].length==0){
            return 0;
        }

        int maxS = 0;
        SubRectangle[][] dp = new SubRectangle[matrix.length+1][matrix[0].length+1];
        //初始化
        for (int i = 0; i < matrix.length+1; i++) {
            dp[i][0] = new SubRectangle(0, 0, 0);
        }
        for (int i = 0; i < matrix[0].length+1; i++) {
            dp[0][i] = new SubRectangle(0, 0, 0);
        }
        //动态规划
        for (int i = 1; i < matrix.length+1; i++) {
            for (int j = 1; j < matrix[0].length+1; j++) {
                if (matrix[i-1][j-1]=='0'){
                    dp[i][j] = new SubRectangle(0, 0, 0);
                }else {
                    //如果添加列
                    SubRectangle subRectangleJT;
                    SubRectangle subRectangleJ = dp[i][j-1];
                    if (subRectangleJ.s==0){
                        //如果之前不构成矩形,检测可构成的最大矩形
                        int y = 0;
                        for (int k = i-1; k >= 0; k--) {
                            if (matrix[k][j-1]=='1'){
                                y++;
                            }else {
                                break;
                            }
                        }
                        subRectangleJT = new SubRectangle(1, y, y);
                    }else{
                        //如果之前构成矩形,检测可构成的最大矩形
                        int y = 0;
                        for (int k = i-1; k >= i-subRectangleJ.ySize; k--) {
                            if (matrix[k][j-1]=='1'){
                                y++;
                            }else {
                                break;
                            }
                        }
                        subRectangleJT = new SubRectangle(subRectangleJ.xSize+1, y, (subRectangleJ.xSize+1)*y);
                    }
                    //如果添加行
                    SubRectangle subRectangleIT;
                    SubRectangle subRectangleI = dp[i-1][j];
                    if (subRectangleI.s==0){
                        //如果之前不构成矩形,检测可构成的最大矩形
                        int x = 0;
                        for (int k = j-1; k >= 0; k--) {
                            if (matrix[i-1][k]=='1'){
                                x++;
                            }else {
                                break;
                            }
                        }
                        subRectangleIT = new SubRectangle(x, 1, x);
                    }else{
                        //如果之前构成矩形,检测可构成的最大矩形
                        int x = 0;
                        for (int k = j-1; k >= j-subRectangleI.xSize; k--) {
                            if (matrix[i-1][k]=='1'){
                                x++;
                            }else {
                                break;
                            }
                        }
                        subRectangleIT = new SubRectangle(x, subRectangleI.ySize+1, (subRectangleI.ySize+1)*x);
                    }

                    dp[i][j] = (subRectangleIT.s>=subRectangleJT.s ? subRectangleIT: subRectangleJT);
                    maxS = Math.max(dp[i][j].s, maxS);
                }
            }
        }
        return maxS;
    }

    private static class SubRectangle{
        //横轴上占的格子
        int xSize;
        //纵轴上占的格子
        int ySize;
        //面积
        int s;

        public SubRectangle(int xSize, int ySize, int s) {
            this.xSize = xSize;
            this.ySize = ySize;
            this.s = s;
        }
    }
}
``` 
