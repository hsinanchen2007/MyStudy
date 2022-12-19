### 解题思路
傻办法是一个个比较，效率比较低是N*M
N个二分法效率是N*logM
一个大佬讲过，10个人写二分法，9个人写不对，是真的，有很多边界，一定搞清楚
1. 开始和结束，结束是数组长度减一
2. while判断条件是<=
3. mid要考虑溢出情况
4. 如果一次没找到，下次下标要加一或减一
else if (matrix[i][mid] > target) {
                   ** end = mid - 1;**
                } else {
                   ** begin = mid + 1;**
                }

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if (matrix.length == 0) {
            return false;
        }
        for (int i = 0; i < matrix.length; i++) {
            if (matrix[i].length == 0) {
                return false;
            }
            int begin = 0;
            int end = matrix[0].length - 1;
            if (matrix[i][0] > target) {
                continue;
            }
            while (begin <= end) {
                int mid = begin + (end - begin) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                } else if (matrix[i][mid] > target) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            }
        }
        return false;
    }
}
```