Xjj

### 代码

```csharp
public class Solution {
    public int MinIncrementForUnique(int[] A) {
         Array.Sort(A);
            int move = 0;
            for (int i = 0; i < A.Length; i++)
            {
                if (i + 1 == A.Length)
                {
                    break;
                }
                while (A[i] >= A[i + 1])
                {
                    move += A[i] - A[i + 1] + 1;
                    A[i + 1] = A[i] + 1;
                }
            }
            return move;
        }
}
```