先对称旋转，之后再按行旋转
```
class Solution {
    public void rotate(int[][] matrix) {    
        // 先对称旋转
        int len = matrix.length;
        for(int i=0; i<len; i++){
            for(int j=i+1; j<len; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp; 
            }
        }
        
        // 按行旋转
        for(int i=0; i<len; i++){
            int right = len-1;
            int left = 0;
            while(left < right){
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
                right --;
                left ++;
            }
        }
    }
}
```