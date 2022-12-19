### 解题思路
第一次在力扣上做题：暴力解法，直接遍历数组。
还需认真思考其他简单解法，加油！
### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
}
```