# 排序+双指针
```
public IList<IList<int>> ThreeSum(int[] nums)
{
    // 排序
    Array.Sort(nums);
    var result = new List<IList<int>>();
    for (int index = 0; index < nums.Length - 2; index++)
    {
        // 排序后跟前一个数字比较即可排除重复
        if (index > 0 && nums[index] == nums[index - 1]) continue;
        // 使用双指针在index后面的部分查找
        int left = index + 1, right = nums.Length - 1;
        while (left < right)
        {
            var sum = nums[index] + nums[left] + nums[right];
            if (sum > 0)
            {
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                result.Add(new List<int>() { nums[index], nums[left], nums[right] });
                // 指针需要跳过相同的数字后继续匹配
                while (left < right && nums[right] == nums[right - 1]) right--;
                while (left < right && nums[left] == nums[left + 1]) left++;
                right--; left++;
            }
        }
    }
    return result;
}
```

# 回溯法（超时）
```
public IList<IList<int>> ThreeSum(int[] nums)
{
    // 排序后用于避免重复
    Array.Sort(nums);
    var current = new List<int>();
    var result = new List<IList<int>>();
    Backtrack(0, nums, current, result);
    return result;
}

public void Backtrack(int start, int[] nums, List<int> current, List<IList<int>> result)
{
    if (current.Count == 3)
    {
        if (current.Sum() == 0)
        {
            result.Add(new List<int>(current));
        }
        return;
    }

    // HashSet 用于避免本层重复
    var hashSet = new HashSet<int>();
    for (int index = start; index < nums.Length; index++)
    {
        if (hashSet.Contains(nums[index])) continue;
        hashSet.Add(nums[index]);
        current.Add(nums[index]);
        Backtrack(index + 1, nums, current, result);
        current.RemoveAt(current.Count - 1);
    }
}
```