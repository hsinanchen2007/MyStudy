### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
int row = matrix.length;
int col = matrix[0].length;
int [][]flag = new int[row][col];
for(int i=0;i<row;i++)
{
      int k =row-1;
    for(int j=0;j<col;j++)
    {
flag[i][j] = matrix[k][i];
    k--;
    }
}
for(int i=0;i<row;i++)
{
    for(int j=0;j<col;j++)
    {
matrix[i][j] = flag[i][j];
    }
}

    }
}
```