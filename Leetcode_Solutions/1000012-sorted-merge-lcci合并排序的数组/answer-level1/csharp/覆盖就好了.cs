### 解题思路
从指定位置覆盖然后利用Sort排序

### 代码

```csharp
public class Solution {
    public void Merge(int[] A, int m, int[] B, int n) {
        for (int i = 0; i < n; i++)
            {
                A[m + i] = B[i];
            }
            Array.Sort(A);
    }
}
```