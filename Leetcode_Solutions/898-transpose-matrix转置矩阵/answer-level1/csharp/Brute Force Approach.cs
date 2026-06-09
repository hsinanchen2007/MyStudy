### 解题思路
Brute force solution: using a nested for-loop.

### 代码

```csharp
public class Solution {
    public int[][] Transpose(int[][] A) {
        if (A.Length == 0) { return A; }
        
        int[][] transposed = new int[A[0].Length][];
        for (int i = 0; i < A[0].Length; i++) {
            int[] transposedColumns = new int[A.Length];
            for (int j = 0; j < A.Length; j++) {
                transposedColumns[j] = A[j][i];
            }
            transposed[i] = transposedColumns;
        }

        return transposed;
    }
}
```