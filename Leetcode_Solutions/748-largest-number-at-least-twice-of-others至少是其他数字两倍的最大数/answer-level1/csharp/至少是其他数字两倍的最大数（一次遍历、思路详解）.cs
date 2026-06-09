**解题：**

分析题目要求（查找数组中的最大元素是否至少是数组中每个其他数字的两倍），我们的需求一目了然：

- 取得数组中最大数及第二大的数。

*（只要数组中的最大数是大于第二大的数的两倍时，那么这个最大数也便是其它数的至少两倍）*

那么，如何取得最大数呢？

其实很简单：由于最大数只有一个，其它数必然比其小。故只需要取得数组中任意一个数，并将其与数组中的所有其它的数进行比较，如果有大于它的数，便保留下来。依次类推，仅需要一次遍历即可。

而第二大的数只需要在保存最大的数时前一步保存最大数，那么，其便为已知当前第二大的数。

综上所述，得代码如下：

```csharp []
public int DominantIndex(int[] nums) 
{
    if(nums.Length == 1)
        return 0;;
    //由于此时可以保证数组含有至少两个元素，所以第二大的数必然会被赋值
    int smallerNumber = int.MinValue;
    //返回的是最大数的下标，所以只需要保留最大数的下标即可。
    int maxNumberIndex = 0;
    for(int i = 1;i < nums.Length;i++)
    {
        if(nums[i] > nums[maxNumberIndex])
        {
            //保留当前已知最大数。并更新第二大的数的值
            smallerNumber = nums[maxNumberIndex];
            maxNumberIndex = i;
        }
        else if(nums[i] > smallerNumber)//一个数小于最大数，不一定小于第二大的数
            smallerNumber = nums[i];;
    }
    //很好理解的数学关系
    return smallerNumber * 2 <= nums[maxNumberIndex] ? maxNumberIndex : -1;
}
```
```cpp []
int dominantIndex(vector<int>& nums) {
    if(nums.size() == 1)
        return 0;;
    //由于此时可以保证数组含有至少两个元素，所以第二大的数必然会被赋值
    int smallerNumber = INT_MIN;
    //返回的是最大数的下标，所以只需要保留最大数的下标即可。
    int maxNumberIndex = 0;
    for(int i = 1;i < nums.size();i++){
        if(nums[i] > nums[maxNumberIndex]){
            //保留当前已知最大数。并更新第二大的数的值
            smallerNumber = nums[maxNumberIndex];
            maxNumberIndex = i;
        }
        else if(nums[i] > smallerNumber)//一个数小于最大数，不一定小于第二大的数
            smallerNumber = nums[i];;
    }
    //很好理解的数学关系
    return smallerNumber * 2 <= nums[maxNumberIndex] ? maxNumberIndex : -1;
}
```

虽然还有其它方法，但我觉得原理大多相仿，就不在此一一介绍了。

希望对大家能有所帮助！

————编辑历史

二零一九年八月一十八日：经[@whj1995](/u/whj1995)的提示，已将代码中代表第二大值的变量（smallerNumber）的初始值由 0 改为 int 类型所能支持的最小值。
