### 解题思路
此处撰写解题思路
害，一开始想到的就是折半查找
### 代码
时间复杂度O（m*logn）
```java
class Solution {
        public boolean findNumberIn2DArray(int[][] matrix, int target) {
            int b = matrix.length;
            for (int i = 0; i < b; i++) {
                int flag = Reduce_Search(matrix[i], target);
                if (flag == 0)
                    return true;
            }
            return false;
        }

        public int Reduce_Search(int[] array, int target) {
            int low = 0;
            int heigh = array.length - 1;
            while (low <= heigh) {
                int mid = (low + heigh) / 2;
                if (array[mid] == target) {
                    return 0;
                } else if (array[mid] > target) {
                    heigh = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return -1;
        }
    }
```