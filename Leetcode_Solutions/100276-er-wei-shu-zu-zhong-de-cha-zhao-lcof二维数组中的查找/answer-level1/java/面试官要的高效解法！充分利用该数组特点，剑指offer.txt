### 解题思路
利用数组特性，从数组左下角开始查询；同理，客官可尝试从右上角开始遍历！1
![捕获.PNG](https://pic.leetcode-cn.com/73a6efd71da853052813ecf30e360266361a7d6d303425c6e6dddbe75f43101f-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix==null || matrix.length==0)
            return false;
        int rows = matrix.length;
        int cols = matrix[0].length;
        int row = rows - 1;
        int col = 0;
        while(row>=0&&col<cols){
            if(matrix[row][col] == target){
                return true;
            }
            if(matrix[row][col]>target){
                row--;
            }else if(matrix[row][col]<target){
                col++;
            }
        }
        return false;
    }
}
```