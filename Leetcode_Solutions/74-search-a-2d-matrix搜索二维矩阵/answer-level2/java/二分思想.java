每个矩形的右上角都是一个切分点
如果该点的值小于target那么该点所在行必然不存在target
如果该点的值大于target那么该点所在列必然不存在target

```Java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if( matrix.length ==0 )return false;
        int i=0,j=matrix[0].length-1;
        while(i<matrix.length && j>=0){
            int val = matrix[i][j];
            if(val==target)
                return true;
                
            if(val>target){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
}
```
