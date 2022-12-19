### 解题思路
注意要旋转的点是矩阵的边框顶点，遍历每个顶点，对其做四次变换就可以了

### 代码

```csharp
public class Solution {
    public void Rotate(int[][] matrix) {
        int n = matrix.Length;
        int count = 0;
        for(int i = 0;i<n-1;i++){
            for(int j = i;j < n-i-1;j++){
                rotate(matrix,i,j,matrix[i][j],count);
            }
        }
    }
    public void rotate(int[][] matrix,int i ,int j,int val,int count){
        int temp = 0;
        if(count <= 3){
            temp = matrix[j][matrix.Length-i-1];
            matrix[j][matrix.Length-i-1] = val;
            count++;
            rotate(matrix,j,matrix.Length-i-1,temp,count);
        }
    }
}
```