我并不认为我的算法效率高，但是能省掉的地方我都尽量省略掉了。
```
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix.length==0||matrix[0].length==0){
            return false;
        }
        for(int i=0;i<matrix.length;i++){
            int j=matrix[i].length/2;
            while(matrix[i][j]>target&&j>0){
                j--;
            }
            if(target==matrix[i][j]){
                return true;
            }
            while(matrix[i][j]<target&&j<matrix[i].length-1){
                j++;
                
            }
            if(target==matrix[i][j]){
                return true;
            }
        }
        return false;
    }
}
```
做起来比较笨，就是二分查找的具体实现。因为题上给出的数据是有序的，那么就可以采用这种取巧的办法，每一行可以排除一半的数据，但实际算法还是存在O(n^2)的高开消
