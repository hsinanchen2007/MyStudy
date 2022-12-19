class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for(int i=0;i<n/2;i++){  //将矩阵分成n/2个环
            int k=n-i-1;
            for(int j=i;j<k;j++){     //每个环看成是四条（n-2*i-1）长的线段拼接而成，旋转四条边
                int temp=matrix[i][j];
                matrix[i][j]=matrix[n-j-1][i];
                matrix[n-j-1][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=temp;
            }
        }
    }
- }