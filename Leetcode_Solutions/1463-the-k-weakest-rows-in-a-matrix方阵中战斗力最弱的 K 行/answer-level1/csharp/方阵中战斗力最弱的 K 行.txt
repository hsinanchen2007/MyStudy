### 代码

```csharp
public class Solution {
    public int[] KWeakestRows(int[][] mat, int k)
        {
            Dictionary<int, int> dict = new Dictionary<int, int>();
            for (int i = 0; i < mat.Length; i++)
            {
                    dict.Add(i, mat[i].Sum());
            }

            return  dict.OrderBy(t => t.Value).Select(t => t.Key).Take(k).ToArray();
        }
}
```