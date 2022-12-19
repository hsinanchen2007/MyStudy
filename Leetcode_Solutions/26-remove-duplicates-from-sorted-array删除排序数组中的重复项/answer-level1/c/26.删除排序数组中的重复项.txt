### 方法1：暴力移位法
和前一项不一样，保留；否则，全部往前挪一个位置。
时间复杂度为O(n^2)，很明显不好，需要优化。

### 代码

```c
int removeDuplicates(int* nums, int numsSize){


    if(numsSize <= 1)
        return numsSize;

    int last = nums[0];

    for(int i = 1; i <= (numsSize-1); i++)
    {
        if(nums[i] == last)
        {
            for(int j = i; j <= (numsSize-2); j++)
            {
                nums[j] = nums[j+1];
            }
            i--;
            numsSize--;
        }
        else
        {
            last = nums[i];
        }
    }
    return numsSize;     
}
```

### 方法2：建立虚拟的数组
同样采用遍历，若元素和虚拟数组当前元素不一样，更新虚拟数组的下一元素
时间复杂度为O(n)。

### 代码

```c
int removeDuplicates(int* nums, int numsSize){


    if(numsSize <= 1)
        return numsSize;

    int index = 1;

    for(int i = 1; i <= (numsSize-1); i++)
    {
        if(nums[index-1] != nums[i])
        {
            nums[index++] = num[i];
        }
    }
    return index;     
}
```