### 解题思路
使用逆序指针合并两个有序数组

### 代码

```csharp
public class Solution {
    public void Merge(int[] A, int m, int[] B, int n) {
        for (int position = m + n - 1; position >= 0; position--)
        {
            if (m == 0)
            {
                A[position] = B[--n];
            }
            else if (n == 0)
            {
                A[position] = A[--m];
            }
            else
            {
                if (A[m - 1] > B[n - 1])
                {
                    A[position] = A[--m];
                }
                else
                {
                    A[position] = B[--n];
                }
            }
        }
    }
}
```