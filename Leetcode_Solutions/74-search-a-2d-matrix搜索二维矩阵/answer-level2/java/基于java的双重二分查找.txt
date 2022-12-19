执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :41.2 MB, 在所有 java 提交中击败了60.89%的用户
首先通过二分法比较最后一列的值来找出目标值所在的行，再在行中用二分法查找是否存在。
```
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0)
            return false;
        // find row
        int begin = 0;
        int end = matrix.length - 1;
        int mid;
        while(begin != end){
            mid = begin + (end - begin)/2;
            if(matrix[mid][matrix[mid].length - 1] == target )
                return true;
            if(matrix[mid][matrix[mid].length - 1] > target){
                end = mid;
            }else{
                begin = mid + 1;
            }
        }
        int[] arr = matrix[end];
        // find val
        begin = 0;
        end = arr.length-1;
        while(begin != end){
            mid = begin + (end - begin)/2;
            if(arr[mid] == target)
                return true;
            if(arr[mid] > target){
                end = mid;
            }else{
                begin = mid + 1;
            }
        }
        if(arr[begin] == target)
            return true;
        else return false;
    }
}
```
