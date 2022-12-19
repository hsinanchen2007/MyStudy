**思路详解：**

**如果看不下去，代码可能更好理解

题目条件：每个元素最多出现两次。

分析**最终所求**的数组元素每个元素，我们可以发现每个元素必须得满足以下任意一个条件（排除第一个元素）：

一、元素（[]中的元素）左边的元素与该元素不同，但和右边的元素相同（……甲、[乙]、乙、丙……）。

二、元素（[]中的元素）左边的元素与该元素相同，但和右边的元素不同（……甲、乙、[乙]、丙……）。

三、元素（[]中的元素）左右两边的元素都与该元素不同（……甲、[乙]、丙……）。

依据以上已知条件，我们可以通过数组的遍历，并用一个变量记录不同元素中首次出现的元素的下标来进行排列。

**逻辑如下：**

定义一个变量 甲 ，保存顺序遍历数组时，其最近一次出现的元素的下标，或是最近一次出现的第二个元素的下标（第一个和第二个值相等）。

假设此时我们获取了数组中的了某个元素的下标，来自于我们顺序遍历数组。

如果当前下标所对应的元素值等于下标 甲 所对应的元素值，并且该下标满足：甲 + 1 = 该下标，则当前下标为最近出现的数字的第二次出现的数字。由于我们需要保留此数字，为了避免使其被替换，将 甲 赋值为当前下标。

如果当前下标所代表的数字不等于 甲 所对应的数字，那么这肯定是新出现的数字。将 甲 加一，再将 甲 所对应的元素赋值为 当前下标所对应的数字。

**代码如下：**

突然发现，之前我写了好多不大必要代码，这是基于原代码优化后的（但原代码大概会更好理解写）：

```csharp []
public static int RemoveDuplicates(int[] nums)
{
    if (nums.Length <= 2)
        return nums.Length; ;
    int lastNumberIndex = 1;
    for (int i = 2; i < nums.Length; i++)
    {
        if (nums[i] == nums[lastNumberIndex] && nums[lastNumberIndex] == nums[lastNumberIndex - 1])
            continue; ;
        nums[++lastNumberIndex] = nums[i]; 
    }
    return ++lastNumberIndex;
}
```

原代码：

```csharp [C#]
public int RemoveDuplicates(int[] nums) 
{
    //乱七八糟的优化
    if (nums.Length <= 2)
        return nums.Length; ;
    //此变量代表着循环中最近出现的数字的下标（……甲、[乙]、乙、丙…… 或 ……甲、乙、[乙]、丙……）
    int lastNumberIndex = 1;
    for (int i = 2; i < nums.Length; i++)
    {
        //判断当前循环下所取得的值是否为第二次重复出现的数字
        if (nums[i] == nums[lastNumberIndex] && nums[lastNumberIndex] != nums[lastNumberIndex-1])
        {
            lastNumberIndex++;
            nums[lastNumberIndex] = nums[i];
        }
        else if (nums[i] != nums[lastNumberIndex])//如果这是不同于最近所出现的数字，即新数字，则在最近排序的数字后一位赋值为当前数字。注意 ++lastNumberIndex 已将 lastNumberIndex 的值更新
            nums[++lastNumberIndex] = nums[i];;
    }
    //最后一步，返回结果。由于数组长度大于数组最后一个索引值一个一，所以采用“所得下标值加一”的方法返回符合要求的数
    return ++lastNumberIndex;
}
```
其实代码比较好容易理解，再加上我精心准备的注释，应该看一遍就大概理解得差不多了，我也就不再赘言了。

如果各位道友实在是难以理解的话，推荐Visual Studio或更强的玩意去 F10 F11 跑一遍。

***温馨提示：调试的时候注意观察数组每个项的变化规律*