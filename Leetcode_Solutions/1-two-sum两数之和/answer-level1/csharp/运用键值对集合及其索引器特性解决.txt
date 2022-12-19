**前言：**

由于在**C Sharp**中键值对集合的实现基于哈希表，所以在键值对集合中不允许添加重复的键。但如果通过键值对集合所以提供的**索引器**（Item[TKey]）去添加键，哪怕键值对集合中已存在相同的键却不会抛出异常。其原因是**C Sharp**允许开发人员通过索引器去添加新键和获取或修改键所对应的值。

在此题中，通过索引器做的最大优势是将使得代码中每一步操作接近 **O(1)** 。但是如果通过 Array 类中所提供的 IndexOf 方法去寻找合适的索引，其操作为**O（n）**

————部分资料来自于：https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic.dictionary-2.item?view=netframework-4.8#System_Collections_Generic_Dictionary_2_Item__0_；https://docs.microsoft.com/zh-cn/dotnet/api/system.array.indexof?view=netframework-4.8

**逻辑分析：**

如果我们需要判断数组中一个数与数组中的另一个可能存在的数相加是否等于所要求的数。它们之间将符合以下条件：

因为：当前数 + 可能存在的数 = 目标数

所以：可能存在的数 = 目标数 - 当前数

有了以上逻辑关系，我们只需要判断 可能存在的数 是否存在于键值对集合当中即可。

**代码如下：**

```csharp []
public static int[] TwoSum(int[] nums, int target)
{
    Dictionary<int, int> numberIndexPairs = new Dictionary<int, int>();
    for (int i = 0; i < nums.Length; i++)
    {
        //如果 numberIndexPairs[nums[i]] = i 在判断前，那么可能将不符合“你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素”中的条件
        // ContainsKey 的操作接近 O（1），这是由于键值对集合的实现运用了哈希表
        if (numberIndexPairs.ContainsKey(target - nums[i]))
        {
            return new int[] { i, numberIndexPairs[target - nums[i]] };
        }
        //通过索引器添加新键，如果此键为重复的键，将更新当前键所对应的值
        numberIndexPairs[nums[i]] = i;
    }
    return new int[] { };
}
```

**总结**

没啥好总结的，但值得注意的是：在键值对集合中添加值，索引器有索引器的优势，但 Add 方法可以确保已收入的键值对不被意外地更新。
