### 解题思路
因为A刚好留下了足够容纳B的空间，所以可以直接从A的尾巴开始比较，将大的数从后往前填满数组。。

### 代码

```csharp
public class Solution {
    public void Merge(int[] A, int m, int[] B, int n) {
        for (int i = m + n - 1; i >= 0; i--)
         {
            if(m > 0 && n > 0)
            {
                A[i] = A[m - 1] > B[n - 1] ? A[m-- - 1] : B[n-- - 1];
            }
            else if (m > 0) break;
            else A[i] = B[n-- - 1];
        }
    }
}
```