### 解题思路
居然没有超时。。我的思路就是正常遍历然后和目标比较，相同返回true,遍历完成都没有返回false.

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        for(int i = 0;i<matrix.length;i++) {
            for(int j = 0;j<matrix[0].length;j++) {
                if(matrix[i][j]==target) return true;
            }
        }
        return false;
    }
}
```