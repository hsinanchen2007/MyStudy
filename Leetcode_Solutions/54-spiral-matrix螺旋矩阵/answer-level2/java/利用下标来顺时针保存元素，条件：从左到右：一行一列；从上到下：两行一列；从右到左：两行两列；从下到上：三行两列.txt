执行用时 :0 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :34.2 MB, 在所有 java 提交中击败了81.01%的用户
```
class Solution {

    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList();
        if(matrix == null || matrix.length < 1 || matrix[0].length < 1)
            return list;
        int startrow = 0;
        int startcol = 0;
        int endrow = matrix.length-1;
        int endcol = matrix[0].length-1;
        while(startrow*2 < matrix.length && startcol*2 < matrix[0].length){
            getResult(startrow++, endrow--, startcol++, endcol--, list, matrix);
        }
        return list;
    }
    public void getResult(int startrow, int endrow, int startcol, int endcol, List<Integer> list, int[][] matrix){
        if(startcol <= endcol){
            for(int i = startcol; i <= endcol; i++){
                list.add(matrix[startrow][i]);
            }
            startrow++;
        }
        if(startrow <= endrow){
            for(int i = startrow; i <= endrow; i++){
                list.add(matrix[i][endcol]);
            }
            endcol--;
        }
        if(startrow <= endrow && startcol <= endcol){
            for(int i = endcol; i >= startcol; i--){
                list.add(matrix[endrow][i]);
            }
            endrow--;
        }
        if(startrow <= endrow && startcol <= endcol){
            for(int i = endrow; i >= startrow; i--){
                list.add(matrix[i][startcol]);
            }
        }
    }
}
```
