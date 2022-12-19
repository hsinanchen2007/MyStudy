### 解题思路
新手
### 代码

```csharp
public class Solution {
    public int LengthOfLIS(int[] nums) {
        if (nums.Length == 0) return 0;
        IList<int> result = new List<int>();
        result.Add(nums[0]);
        for (int i = 1; i < nums.Length; i++)
        {
            int a = nums[i];
            int index = binarysearch(result, a);
            if (index < result.Count)
                result[index] = a;
            else
                result.Add(a);
        }
        return result.Count;
    }
    public static int binarysearch(IList<int> nums, int val)
    {
        int lo = 0;
        int hi = nums.Count - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] > val)
                hi = mid - 1;
            else if (nums[mid] < val)
                lo = mid + 1;
            else
                return mid;
        }
        return lo;
    }
}

```