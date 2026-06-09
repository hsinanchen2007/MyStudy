```
class Solution {
    public void setZeroes(int[][] matrix) {
        Set<Integer> zeroRow = new HashSet<>();
        Set<Integer> zeroCol = new HashSet<>();
        for(int i =0;i<matrix.length;i++){
            for(int j =0;j<matrix[i].length;j++){
                if(matrix[i][j]==0){
                    zeroRow.add(i);
                    zeroCol.add(j);
                }
            }
        }
        for(Integer i : zeroRow){
            for(int j = 0;j<matrix[i].length;j++){
                matrix[i][j]=0;
            }
        }
        for(Integer i:zeroCol){
            for(int j = 0;j<matrix.length;j++){
                matrix[j][i]=0;
            }
        }
    }
}
```
