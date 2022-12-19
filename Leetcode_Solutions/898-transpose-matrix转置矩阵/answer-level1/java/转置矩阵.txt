### 解题思路


### 代码

```java
class Solution {
    public int[][] transpose(int[][] A) {
        int row=A.length;
        int column=A[0].length;

        //新建一个矩阵B，表示矩阵A的转置
        int [][] B=new int[column][row];
        for(int i=0;i<column;i++)
        {
            for(int j=0;j<row;j++)
            {
                B[i][j]=A[j][i];
            }
        }
        return B;
    }
}
```