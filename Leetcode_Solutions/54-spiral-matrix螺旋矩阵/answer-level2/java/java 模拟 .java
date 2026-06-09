```
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        
        if(matrix==null||matrix.length<1){
            return result;
        }
        
        int startRow = 0;
        int endRow = matrix.length;
        int startCol = 0;
        int endCol = matrix[0].length;
        while(startRow<endRow&&startCol<endCol){
            runOneCircle(result,matrix, startRow,endRow,startCol,endCol);
            if(startRow<endRow){
                startRow++;
                endRow--;
            }
            if(startCol<endCol){
                startCol++;
                endCol--;
            }
        }
        return result;
    }
    
    private void runOneCircle(List<Integer> result, int[][] circle, int startrow, int endrow, int startcol, int endcol){
        
        if(endrow-startrow==1){
            for(int i = startcol;i<endcol;i++){
                result.add(circle[startrow][i]);
            }
        }else{
        //add top
        for(int top = startcol;top<endcol;top++){
            result.add(circle[startrow][top]);
        }
        
        //add right
        for(int right = startrow+1;right<endrow;right++){
            result.add(circle[right][endcol-1]);
        }
        
        //add bottom
        for(int bottom = endcol-2;bottom>(startcol-1);bottom--){
            result.add(circle[endrow-1][bottom]);
        }
        if(endcol-startcol!=1){
        //add left
        for(int left = endrow-2;left>startrow;left--){
            result.add(circle[left][startcol]);
        }
        }
        }
    }
}
```
