class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix==null||matrix.length==0||matrix[0].length==0) return false;
        int rows = matrix.length;
        int cols = matrix[0].length;
        int row = rows-1;
        int col = 0;
        while(row>=0 && col<cols){
            int num = matrix[row][col];
            if(num == target) {
                return true;
            }else if(num>target){
                row--;
            }else{
                col++;
            }

        }
        return false;

    }
}