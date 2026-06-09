### 解题思路


### 代码

```csharp
public class Solution {
    public int[][] FindContinuousSequence(int target) {
            int low = 1;
            int hign = 1;
            int sum = 0;
            List<int[]> list = new List<int[]>();
            while (low<=target/2)
            {
                if (sum < target)
                {
                    sum += hign;
                    hign++;
                }
                else if (sum > target)
                {
                    sum -= low;
                    low++;
                }
                else
                {
                    int[] ar = new int[hign - low];
                    int j = low;
                    for (int k = 0; k < hign&&j<hign; k++,j++)
                    {
                        ar[k] = j;
                    }
                    list.Add(ar);
                    sum -= low;
                    low++;
                }
            }
            return list.ToArray();
    }
}
```