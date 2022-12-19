### 解题思路
此处撰写解题思路
1、本题采用贪心算法。即每次都寻找最大长度的情况；
2、目的是获取最大长度，并且使增长幅度尽可能小。后面关键点会有插值替换的过程。这样能保证如果最大值后面长度大于最大值前面序列长度，那么会取后面序列值作为最长序列；

### 代码

```c
int lengthOfLIS(int* nums, int numsSize){
    int length = 0;
    int i = 0, j = 0;
    int *arr = (int *)malloc(sizeof(int) * numsSize);

    if(!numsSize)
    {
        return 0;
    }

    arr[0] = nums[0];
    length = 1;

    for(i = 1; i < numsSize; i++)
    {
        if(nums[i] > arr[length - 1])
        {
            length++;
            arr[length - 1] = nums[i];
        }
        else
        {
            for(j = (length - 2); j >= 0; j--)
            {
                if(arr[j] < nums[i])
                {
                    arr[j + 1] = nums[i];
                    break;
                }
            }

            if(j == -1)
            {
                arr[0] = nums[i];
            }
        }
    }

    return length;
}
```