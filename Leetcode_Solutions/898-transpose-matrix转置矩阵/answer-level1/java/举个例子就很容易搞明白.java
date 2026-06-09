### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] transpose(int[][] A) {
               int row = A.length;
        int col = A[0].length;
        
        int[][] B = new int[col][row];
        
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++){
                B[j][i] = A[i][j];
            }
        }
        
        return B;
    }
}
```