### 解题思路
双指针

### 代码

```csharp
public class Solution {
    public int[][] FindContinuousSequence(int target)
        {
            if (target < 3)
            {
                return null;
            }
            int left = 1;
            int right = 2;
            int mid = (1 + target) / 2;
            var result = new List<List<int>>();

            while (left < mid)
            {
                int currentSum = 0;
                for (int i = left; i <= right; i++)
                {
                    currentSum += i;
                }
                
                if (currentSum == target)
                {
                    var list = new List<int>();
                    for (int i = left; i <= right; i++)
                    {
                        list.Add(i);
                    }
                    result.Add(list);
                    right++;
                }
                else if (currentSum < target)
                {
                    right++;
                }
                else
                {
                    left++;
                }
            }

            int[][] final = new int[result.Count][];
            for (int i = 0; i < final.Length; i++)
            {
                final[i] = result[i].ToArray();
            }

            return final;
        }
}
```