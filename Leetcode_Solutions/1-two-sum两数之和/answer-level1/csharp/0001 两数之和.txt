## [0001 两数之和](https://zdevcs.github.io/leetcode/doc/csharp/0001_TwoSum.html)

给定一个整数数组 `nums` 和一个目标值 `target` ，请你在该数组中找出和为目标值的那 `两个` 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

### 示例：

```markdown
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

### [参考代码：]

```cs
/// <summary>
/// 给定一个整数数组 nums 和一个目标值 target，返回和为 target 的元素下标
/// </summary>
/// <param name="nums"> 整数数组 </param>
/// <param name="target"> 目标值 </param>
/// <returns> 返回和为 target 的元素下标 </returns>
public int[] TwoSum(int[] nums, int target)
{
    var sl = new SortedList<int, int>();

    for (int i = 0; i < nums.Length; i++)
    {
        int value = target - nums[i];
        if (sl.Keys.Contains(value))
            return new[] { sl[value], i };
        sl[nums[i]] = i;
    }
    return null;
}
```

[参考代码：]:https://github.com/zdevcs/leetcode/blob/master/LeetCode-CSharp/0001_TwoSum.cs "查看完整代码"
