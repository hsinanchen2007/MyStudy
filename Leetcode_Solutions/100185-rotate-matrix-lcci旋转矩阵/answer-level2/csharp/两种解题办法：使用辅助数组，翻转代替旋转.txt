### 解题思路一：使用辅助数组
这个思路很简单，也是大家一开始会想到的方法，那就是使用一个辅助数组来储存旋转后的值，待旋转后，再将更新后的值一个个更新到原数组中


#### 代码
```csharp
public class Solution {
    public void Rotate(int[][] matrix) {
        // 执行用时 : 324 ms, 在所有 C# 提交中击败了 30.00% 的用户
        // 内存消耗 : 30.2 MB, 在所有 C# 提交中击败了 100.00% 的用户
        int matrixSize = matrix.Length;
        int[][] transposed = new int[matrixSize][];

        for (int j = 0; j < matrixSize; j++)
        {
            int[] transposedRow = new int[matrixSize];

            for (int i = 0; i < matrixSize; i++)
            {
                transposedRow[matrixSize - i - 1] = matrix[i][j];
            }
            transposed[j] = transposedRow;
        }

        for (int i = 0; i < matrixSize; i++)
        {
            for (int j = 0; j < matrixSize; j++)
            {
                matrix[i][j] = transposed[i][j];
            }
        }
    }
}
```

### 解题思路二：用翻转来代替旋转
这个思路是[官方题解](https://leetcode-cn.com/problems/rotate-matrix-lcci/solution/xuan-zhuan-ju-zhen-by-leetcode-solution/)提供的。

我们首先上下翻转原数组，再沿对角线来翻转原数组。两次反转都需要使用到一个temp的变量来临时储存值。

#### 代码

```csharp
public class Solution {
    public void Rotate(int[][] matrix) {
        // 执行用时: 320 ms, 在所有 C# 提交中击败了 30.00% 的用户
        // 内存消耗: 30.5 MB, 在所有 C# 提交中击败了 100.00% 的用户

        int matrixSize = matrix.Length;
        
        // swap the first upper half of the matrix the second lower half.
        for (int i = 0; i < matrixSize / 2; i++) {
            for (int j = 0; j < matrixSize; j++) {
                int temp1 = matrix[i][j];
                int lowerHalfIndex = matrixSize - i - 1;
                
                matrix[i][j] = matrix[lowerHalfIndex][j];
                matrix[lowerHalfIndex][j] = temp1;
            }
        }

        // flip diagonally.
        for (int i = 0; i < matrixSize; i++) {
            for (int j = 0; j < i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
}
```