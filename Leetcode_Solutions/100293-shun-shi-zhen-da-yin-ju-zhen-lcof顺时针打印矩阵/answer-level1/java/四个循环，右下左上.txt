```
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if(matrix.length==0) return new int[0];
        int x = 0;
        int y = 0;
        int row = matrix.length-1;
        int col = matrix[0].length-1;
        int[] result = new int[(row+1)*(col+1)];
        int index = 0;
        while(x<=row && y<=col){
            //向右
            for(int i= y;i<=col&&index<result.length;i++){
                result[index++] = matrix[x][i];
                
            }
            
            //向下
            for(int i = x+1;i<=row&&index<result.length;i++){
                result[index++] = matrix[i][col];
                
            }
            //向左
            for(int i = col-1;i>=y&&index<result.length;i--){
                result[index++] = matrix[row][i];
            }
            //向上
            for(int i = row-1;i>=x+1&&index<result.length;i--){
                result[index++] = matrix[i][y];
            }
            y++;
            x++;
            col--;
            row--;
        }
        return result;
    }
}
```
唯一值得注意的就是边界一定要算好