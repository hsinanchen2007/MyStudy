双指针法

```
public static int[] SmallestRange(IList<IList<int>> nums)
{
    if (nums.Count == 0) return Array.Empty<int>();
    if (nums.Count == 1) return new[] { nums[0][0], nums[0][0] };

    int start = int.MinValue, end = int.MaxValue;
    var indexMap = new int[nums.Count];
    var nextSet = Enumerable.Range(0, nums.Count).Where(index => nums[index].Count > 1).ToHashSet();
    var oneMoreTime = true;
    while (nextSet.Count > 0 || oneMoreTime)
    {
        int minNextIndex = int.MaxValue,
            minNextValue = int.MaxValue,
            minValue = nums[0][indexMap[0]],
            maxValue = nums[0][indexMap[0]];
        for (int numsIndex = 0; numsIndex < nums.Count; numsIndex++)
        {
            int currentNumsIndex = indexMap[numsIndex];
            int currentValue = nums[numsIndex][currentNumsIndex];
            if (currentValue < minValue)
            {
                minValue = currentValue;
            }
            else if (currentValue > maxValue)
            {
                maxValue = currentValue;
            }

            if (nextSet.Contains(numsIndex) && currentValue < minNextValue)
            {
                minNextValue = currentValue;
                minNextIndex = numsIndex;
            }
        }

        if ((long)maxValue - (long)minValue < (long)end - (long)start)
        {
            start = minValue;
            end = maxValue;
        }

        if (nextSet.Count > 0)
        {
            indexMap[minNextIndex]++;
            if (indexMap[minNextIndex] >= nums[minNextIndex].Count - 1)
                nextSet.Remove(minNextIndex);
        }
        else
        {
            oneMoreTime = false;
        }
    }

    return new[] { start, end };
}
```