class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        #考虑边界情况
        if(matrix == null || matrix.length == 0 || matrix[0].length == 0){
            return new int[0];
        }
        #行边界
        int m=matrix.length-1;
        #列边界
        int n=matrix[0].length-1;
        int [] res=new int[(m+1)*(n+1)];
        #放入第一个元素
        res[0]=matrix[0][0];
        int count=0;
        int i=0,j=0;
        for(int num=1;num<=m+n;num++){
            #为奇数情况 箭头向下
            if(num%2==1){
                if(j<n)
                    j++;
                else{
                    i++;
                }
                count++;
                res[count]=matrix[i][j];
            while(i<m&&j>0){
                i++;
                j--;
                count++;
                res[count]=matrix[i][j];
            }
            }
            else{
                #为偶数情况 箭头向上
                if(i<m)
                  i++;
                else{
                    j++;
                }
                count++;
                res[count]=matrix[i][j];
                while(j<n&&i>0){
                    i--;
                    j++;
                    count++;
                    res[count]=matrix[i][j];
                }

            }
        }
        return res;
    }
}