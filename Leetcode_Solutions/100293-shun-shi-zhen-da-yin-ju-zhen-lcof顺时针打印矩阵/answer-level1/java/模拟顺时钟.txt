### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {

        if (matrix == null || matrix.length == 0)
            return new int[0];
        int rowl = 0;
        int rowh = matrix.length-1;
        int coll = 0;
        int colh = matrix[0].length-1;
        int[] ans = new int[(rowh+1)*(colh+1)];
        int cou = 0;
        while (rowl <= rowh || coll <= colh){
            if (rowl <= rowh && coll <= colh){
                for (int i = coll ; i <= colh ; i++){
                    ans[cou] = matrix[rowl][i];
                    cou++;
                }
            }
            rowl++;
            if (rowl <= rowh && coll <= colh){
                for (int i = rowl;i <= rowh; i++){
                    ans[cou] = matrix[i][colh];
                    cou++;
                }
            }
            colh--;
            if (rowl <= rowh && coll <= colh) {
                for (int i = colh;i>= coll; i--) {
                    ans[cou] = matrix[rowh][i];
                    cou++;
                }
            }
            rowh--;
            if (rowl <= rowh && coll <= colh){
                for (int i = rowh;i>=rowl;i--){
                    ans[cou] = matrix[i][coll];
                    cou++;
                }
            }
            coll++;
        }
        return ans;
    }
}
```