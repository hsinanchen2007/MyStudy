### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public bool FindNumberIn2DArray(int[][] matrix, int target) {
        for(int i=0;i<matrix.Length;i++){
            for(int j=0;j<matrix[i].Length;j++){
                if(matrix[i][j] == target)
                     return true;                                                
            }            
        }
        return false;
    }
}
```