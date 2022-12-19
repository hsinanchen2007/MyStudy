很直观的想法，第一次二分查找确定所要查找的数所在的行，第二次二分查找确定要找到的数列所在的列，最后比较最后定位到的数和target是否相等，相等返回true，不等返回false。
```
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int begin = 0;
        int end = matrix.length-1;
        int mid;
        if(matrix.length == 0||matrix[0].length == 0)
            return false;
        while(begin < end)
        {
            mid = (begin+end+1) >>> 1;
            if(matrix[mid][0]>target)
            {
                end = mid -1;
            }
            else
            {
                begin = mid;
            }
        }
        int l = 0;
        int r = matrix[0].length-1;
        while(l < r)
        {
            mid = (l+r) >>> 1;
            if(matrix[end][mid]<target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        if(matrix[end][l]==target)
            return true;
        else
        {
            return false;
        }
    }
}
```
