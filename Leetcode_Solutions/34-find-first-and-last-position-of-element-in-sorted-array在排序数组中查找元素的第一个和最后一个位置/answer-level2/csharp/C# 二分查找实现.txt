C# 二分查找实现 
```
/// <summary>
/// 二分查找法
/// </summary>
/// <param name="nums"></param>
/// <param name="target"></param>
/// <returns></returns>
public int[] SearchRange(int[] nums, int target)
{
    int left = 0;
    int right = nums.Length - 1;
    int privot = (left + right) / 2;
    while (left <= right)
    {
        privot = (left + right) / 2;
        if (nums[privot] > target)
        {
            right = privot - 1;
        } else if (nums[privot] < target)
        {
            left = privot + 1;
        } else
        {
            int rangeLeft = privot;
            int rangeRight = privot;
            while (rangeLeft - 1 >= 0 && nums[rangeLeft - 1] == target)
            {
                rangeLeft -= 1;
            }

            while (rangeRight + 1 < nums.Length && nums[rangeRight + 1] == target)
            {
                rangeRight += 1;
            }
            return new int[] { rangeLeft, rangeRight };
        }
    }
    return new int[] { -1, -1 };
}
```
