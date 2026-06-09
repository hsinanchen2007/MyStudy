

### 代码

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target)
    {
        Dictionary<int,int> dicnums = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++)
        {
            if (!dicnums.ContainsKey(nums[i]))
            {
                dicnums.Add(nums[i],i);
            }
            else
            {
                if (nums[i] * 2 == target)
                {
                    return new int[2]{dicnums[nums[i]],i};
                }
            }
        }

        List<int> sortednums = nums.ToList();
        sortednums.Sort();
        for (int i = 0, j = nums.Length - 1;i < j;)
        {
            while (sortednums[i] + sortednums[j] != target)
            {
                if (sortednums[i] + sortednums[j] > target)
                {
                    j--;
                }
                else
                {
                    i++;
                }
            }
            return new int[2]{dicnums[sortednums[i]],dicnums[sortednums[j]]};
        }

        return null;
    }
}
```