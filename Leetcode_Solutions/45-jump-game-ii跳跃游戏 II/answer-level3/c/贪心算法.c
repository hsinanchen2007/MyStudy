### 解题思路
这题用贪心算法来做，每次跳到的元素必须是下次能跳最远的，如果
后面的元素都不如当前位置元素可以跳到的下标更远，则直接在当前元素
跳到能跳到最远的位置

### 代码

```c
int jump(int* nums, int numsSize)
{
    if (numsSize == 0)
        return true;

    int i, j;
    int max = nums[0];
    int index = 0;
    int count = 0;

    for (i = 0; i < numsSize - 1; i = index)//每次跳到选择的元素，见下面
    {   
        if (i + max >= numsSize - 1)//如果从当前坐标能直接跳到最后，则count递增1，然后返回
            return ++count;

        max = nums[i];
        count++;//每跳一次递增一次
        
        for (j = i; j <= i + nums[i]; j++) 
        {
            if (max + index <= nums[j] + j)//选择下次能跳到最远的下标的元素
            {
                index = j;//找到该元素的下标
                max = nums[j];
            }
        }

        if (i == index)//如果没有该元素，直接从当前位置跳到最远的位置
            index += max;
    }

     return count;
}
```