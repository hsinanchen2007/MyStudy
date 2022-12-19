### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public void Merge(int[] A, int m, int[] B, int n) {
        int   index = 0;
            for (int i = m; i <n+m; i++)
            {
                A[i] = B[index];
                index++;
            }

            Array.Sort(A);
            for (int i = 0; i < A.Length; i++)
            {
                Console.WriteLine(A[i]);
            }

    }
}
```