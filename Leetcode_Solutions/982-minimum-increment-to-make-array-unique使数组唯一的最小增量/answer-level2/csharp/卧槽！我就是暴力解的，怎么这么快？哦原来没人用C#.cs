### 解题思路

直接用Array.sort排序，然后检查A[i]是否大于A[i+1]，如果大于，move和A[i + 1]加上差值+1。

### 代码

```csharp
public class Solution {
    public int MinIncrementForUnique(int[] A)
        {
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