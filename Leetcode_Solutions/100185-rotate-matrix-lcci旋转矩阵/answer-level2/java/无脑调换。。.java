

```java
class Solution {
     public void rotate(int[][] matrix) {
        //从下往上第1列变为新数组的第1行，以此类推。
        int x=0;
        int[][] a=new int[matrix.length][matrix[0].length];
        for(int i=0;i<matrix[0].length;i++){
            for(int j=matrix.length-1;j>=0;j--){
                a[i][x++]=matrix[j][i];
            }
            x=0;
        }
        //貌似不能更改引用通过
        for(int i=0;i<a.length;i++){
            for(int j=0;j<a[i].length;j++){
                matrix[i][j]=a[i][j];
            }
        }
    }
}
```