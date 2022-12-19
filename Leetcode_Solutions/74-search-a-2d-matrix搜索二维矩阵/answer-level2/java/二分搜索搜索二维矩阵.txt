### 解题思路
**逐行判断：**
1. 当一行第一个元素大于目标元素，肯定不在这行
2. 当一行最后一个元素小于目标元素，肯定不在这行
3. 找到目标行，使用二分搜索
尤其需要注意的条件是：
int left = 0;
int right = arr.length - 1;
int mid = (left + right) / 2;
while(left <= right){
    if(arr[mid] == target){
        return true;
    }
    if(arr[mid] > target){
        right = mid - 1;
    }else{
        left = mid + 1;
    }
    mid = (left + right) / 2;        
}

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        if(m == 0){
            return false;
        }
        int n = matrix[0].length;
        if(n == 0){
            return false;
        }
        for(int i = 0; i < m; i++){
            if(matrix[i][0] > target){
                return false;
            }
            if(matrix[i][n - 1] < target){
                continue;
            }
            return binarySearch(matrix[i], target);
        }
        return false;
    }

    public boolean binarySearch(int[] arr, int target){
        int left = 0;
        int right = arr.length - 1;
        int mid = (left + right) / 2;
        while(left <= right){
            if(arr[mid] == target){
                return true;
            }
            if(arr[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
            mid = (left + right) / 2;        
        }
        return false;
    }
}
```