### 解题思路
打开，多指针O(n)

### 代码

```csharp
public class Solution {
    public void Merge(int[] A, int m, int[] B, int n) {
            int flagOfA = m-1;
            int flagOfB = n - 1;
            int flagOfResult = m +n - 1;

            while (flagOfA >= 0 && flagOfB >= 0)
            {
                if (A[flagOfA] < B[flagOfB])
                {
                    A[flagOfResult] = B[flagOfB];
                    flagOfB--;
                    flagOfResult--;
                }
                else
                {
                    A[flagOfResult] = A[flagOfA];
                    flagOfA--;
                    flagOfResult--;
                }
            }
            while(flagOfB>=0)
            {
                A[flagOfResult--] = B[flagOfB--];
            }
    }
}
```