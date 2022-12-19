### 解题思路
利用递增，剔除一列或一行。从右上或左下开始：
小于右上，剔除最右列；大于右上，剔除最上行。

这样提高了搜索效率，
时间复杂度为O(r_len*c_len)，只要遍历一遍即可。

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        int rows = matrix.length;
        int colomns = matrix[0].length;
        int i = 0 , j = colomns-1;
        while(i <rows && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] > target){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
}
```