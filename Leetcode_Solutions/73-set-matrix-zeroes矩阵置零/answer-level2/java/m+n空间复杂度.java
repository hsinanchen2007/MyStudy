### 解题思路
1、扫描一遍，记录哪些行、那些列有0
2、再遍历一遍二维数组，如果该行该类有0，则将它置为0

### 代码

```java
class Solution {
       //1、扫描一遍，记录哪些行、那些列有0
    //2、再遍历一遍二维数组，如果该行该类有0，则将它置为0
    public void setZeroes(int[][] matrix) {
        boolean[] row=new boolean[matrix.length];
        boolean[] column=new boolean[matrix[0].length];
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==0){
                    row[i]=true;
                    column[j]=true;
                }
            }
        }
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(row[i]||column[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
}
```