### 解题思路
其实就是二分法，把二维下标转化下。

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length==0)return false;
        int R=matrix.length,C=matrix[0].length;
        int left=0,right=R*C-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[mid/C][mid%C]==target){
                return true;
            }else if(matrix[mid/C][mid%C]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return false;
        
    }
}
```