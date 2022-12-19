### 解题思路
合并数组并排序。
如果新数组长度为奇数，取中间值；
如果新数组长度为偶数，取中间两值的平均值。

### 代码

```csharp
public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        List<int> nums = new List<int>();
        nums.AddRange(nums1);
        nums.AddRange(nums2);
        nums.Sort();

        int mid = (int)Math.Ceiling((double)nums.Count / 2);
        if (nums.Count % 2 == 0)
        {
            return (double)(nums[mid - 1] + nums[mid]) / 2;
        }
        else
        {
            return (double)nums[mid - 1];
        }
    }
}
```