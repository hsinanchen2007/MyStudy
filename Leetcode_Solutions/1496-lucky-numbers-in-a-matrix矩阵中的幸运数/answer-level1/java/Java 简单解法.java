**//解题思路**
//先找出每个一维数组中的最小值，记住下标m，然后遍历二维数组（修改n的值，表示换行）看是不是在同列是最大的。

class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        ArrayList<Integer> lucky = new ArrayList<>();
        int i,j,m=0,n=0;
        for(i=0;i<matrix.length;i++)
        {

            for(j=0;j<matrix[i].length;j++)
            {
                if(matrix[i][m]>matrix[i][j])m=j;
            }
            while(n<matrix.length&&matrix[i][m]>=matrix[n][m]){
                n++;
            }
            if(n==matrix.length){
                lucky.add(matrix[i][m]) ;
            }
            n=0;
        }
       return lucky;
    }
}