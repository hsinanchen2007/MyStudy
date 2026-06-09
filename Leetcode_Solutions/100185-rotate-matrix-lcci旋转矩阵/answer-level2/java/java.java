### 解题思路
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
40 MB
, 在所有 Java 提交中击败了
100.00%
的用户

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int length = matrix.length;
        int[][] res = new int[length][length];
        int m=0,n=0;
        for(int i=length-1;i>=0;i--){
            for(int j=0;j<length;j++){
                res[m][n] = matrix[i][j];
                m++;
            }
            n++;
            m=0;
        }
        m=0;n=0;
        for (int i = 0; i < res.length; i++) {
            for (int j = 0; j < res[i].length; j++) {
                matrix[i][j] = res[i][j];
            }
        }
    }
}
```