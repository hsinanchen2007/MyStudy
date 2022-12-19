class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix==null || matrix.length<=0){
            return false;
        }
        int curRow = 0;
        int curColumn = matrix[curRow].length-1;
        int allRow = matrix.length-1;
        while(curRow<=allRow && curColumn >=0){
            if(matrix[curRow][curColumn]==target){
                return true;
            }else if(matrix[curRow][curColumn]>target){
                curColumn--;
            }else{
                curRow++;
            }
        }
        return false;
    }
}