```
class Solution {
    public void setZeroes(int[][] matrix) {
        List<int[]> list = new ArrayList<int[]>();
        //第一步，找出原数组为零的位置（i,j）
        for(int i =0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==0){
                    list.add(new int[]{i,j});
                }
            } 
        }
        //第二步，将找到的位置所在行列设置为零。
         for(int[] a :list){
              int  t=0;
              while(t<matrix.length)matrix[t++][a[1]]=0;
              t=0;
              while(t<matrix[0].length)matrix[a[0]][t++]=0;
            }
    }
}
```
