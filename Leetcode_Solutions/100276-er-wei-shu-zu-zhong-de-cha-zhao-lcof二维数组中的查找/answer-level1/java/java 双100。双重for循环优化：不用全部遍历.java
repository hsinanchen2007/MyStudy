### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix.length==0) return false;
        int len = matrix[0].length - 1;
        for(int i = 0;i < matrix.length;i++){
            for(int j = len;j >= 0 ;j--){//从二维数组的右上角开始遍历
                if(matrix[i][j] < target){//该行左边不用遍历
                    break;
                }
                if(matrix[i][j] > target){//该列下面不用遍历
                    len--;
                }else
                // if(matrix[i][j] == target){
                    return true;
                // }
            }
        }
        return false;
    }
}
```