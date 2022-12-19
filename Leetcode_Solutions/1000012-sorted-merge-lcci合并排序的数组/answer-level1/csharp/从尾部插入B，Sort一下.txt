### 解题思路
有点太偷懒了，使用了现成的API

### 代码

```csharp
public class Solution {
    public void Merge(int[] A, int m, int[] B, int n) {
        for (int i = 0; i < B.Length; i++)
            {
                A[m + i] = B[i];

            }
            Array.Sort(A);
    }
}
```