### 解题思路
对每个一维数组进行二分查找
Time O(nlogn)
Space O(1)

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        boolean ans = false;
        for(int i = 0; i < matrix.length; i++){
            int low = 0;
            int high = matrix[i].length - 1;
            while(low <= high){
                int temp = (low + high) / 2;
                if(matrix[i][temp] > target){
                    high = temp - 1;
                }else if(matrix[i][temp] < target){
                    low = temp + 1;
                }else{
                    return true;
                }
            }
        }
        return ans;
    }
}
```