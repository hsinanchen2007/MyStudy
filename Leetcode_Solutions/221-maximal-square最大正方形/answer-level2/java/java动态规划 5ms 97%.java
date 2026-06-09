
```
class Solution {
    public int maximalSquare(char[][] matrix) {
        if(matrix.length==0||matrix[0].length==0)
            return 0;
        //hor存放水平从右到左连续1的数量
        int[][] hor=new int[matrix.length][matrix[0].length];
        //ver存放垂直从下到上连续1的数量
        int[][] ver=new int[matrix.length][matrix[0].length];
        //初始化hor
        for(int i=0;i<matrix.length;i++){
            int sum=0;
            for(int j=matrix[0].length-1;j>=0;j--){
                if(matrix[i][j]=='0')
                    sum=0;
                else
                    hor[i][j]=++sum;
            }
        }
        //初始化ver
        for(int j=0;j<matrix[0].length;j++){
            int sum=0;
            for(int i=matrix.length-1;i>=0;i--){
                if(matrix[i][j]=='0')
                    sum=0;
                else
                    ver[i][j]=++sum;
            }
        }
        //res存放最大正方形的边长
        int res=0;
        //遍历矩阵
        for(int i=0;i<matrix.length-res;i++){//matrix.length-res是为了减少不必要的计算，因为matrix.length-res到matrix.length-1的点即使都是1也无法更新res
            for(int j=0;j<matrix[0].length-res;j++){
                //跳过为0的节点
                if(matrix[i][j]=='0')
                    continue;
                //temp存放i,j这个点水平和垂直连续1数量的最小值
                int temp=Math.min(hor[i][j],ver[i][j]);
                //垂直遍历寻找最小值
                for(int k=i+1;k<i+temp;k++)
                    if(matrix[k][j]=='0'){
                        temp=k-i;
                        break;
                    }else{
                        temp=Math.min(temp,hor[k][j]);
                    }
                //更新res
                res=Math.max(res,temp);
            }
        }
        return res*res;
    }
}
```
