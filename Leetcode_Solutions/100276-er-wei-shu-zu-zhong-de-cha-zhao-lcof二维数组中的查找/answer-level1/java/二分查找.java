**基本思路**：
1. 每一行做二分查找
2. 若遍历到某一行第一个元素大于 target, 直接返回 false
3. 若遍历到某一行最后一个元素小于 target, 跳过这一行
```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) return false;
        int rowLen = matrix[0].length;
        for(int i=0; i<matrix.length; i++){
            if(matrix[i][0] > target) break;
            if(matrix[i][rowLen-1] < target) continue;
            int low=-1, high=rowLen;
            while(low+1 < high){
                int mid = low + (high-low)/2;
                if(matrix[i][mid] < target) low = mid;
                if(matrix[i][mid] > target) high = mid;
                if(matrix[i][mid] == target) return true;
            }
        }
        return false;
    }
}
```
