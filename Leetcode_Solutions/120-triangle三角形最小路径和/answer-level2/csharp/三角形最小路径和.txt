### 代码

```csharp
public class Solution {
   public int MinimumTotal(IList<IList<int>> triangle)
        {
            int[] result = new int[triangle.Last().Count()];
            for (int i = 0; i < triangle.Count(); i++)
            {
                int temp = -1;
                for (int j = 0; j <= i; j++)
                {
                    if (i == 0)
                    {
                        result[j] = triangle[0][0];
                    }
                    else {
                        if (j == 0)
                        {
                            temp = result[j] + triangle[i][j];
                        }
                        else if (j == triangle[i].Count - 1)
                        {
                            result[j] = result[j - 1] + triangle[i][j];
                            result[j - 1] = temp;
                        }
                        else {
                            var min = Math.Min(result[j - 1] + triangle[i][j], result[j] + triangle[i][j]);
                            result[j-1] = temp;
                            temp = min;
                        }
                    }
                }
            }
            return result.Min();
        }
}
```