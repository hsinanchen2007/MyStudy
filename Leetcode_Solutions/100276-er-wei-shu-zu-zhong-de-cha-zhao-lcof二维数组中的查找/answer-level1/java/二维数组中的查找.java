### 解题思路
从左下角开始搜索，target > 当前数字则向右搜索，反之则向上搜索，需要注意二维数组为空的特殊情况

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] array, int target) {
        int row = array.length;
        if(row == 0){
            return false;
        }
        int col = array[0].length;
        int m = row - 1;
        int n = 0;
        while(m >= 0 && n < col){
            if(target < array[m][n]){
                m--;
            }
            else if(target > array[m][n]){
                n++;
            }
            else{
                return true;
            }
        }
        return false;
    }
}
```