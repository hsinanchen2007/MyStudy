### 解题思路
方法一：通过和 nums[0]比较，分两段进行循环比较

### 代码

```c

//方法一：通过和 nums[0]比较，分两段进行循环比较
int search(int* nums, int numsSize, int target){
    int     i       = 0;
    int     j       = 0;
    int     iTmp    = 0;
    int     iRet    = -1;

    if ((NULL == nums) || (0 == numsSize))
    {
        return iRet;
    }

    if (nums[0] <= target)
    {
        //目标值在前半段
        for (i = 0; i < numsSize; i++)
        {
            if (nums[i] == target)
            {
                iRet = i;
                break;
            }

            if ((i + 1 < numsSize) && (nums[i] > nums[i + 1]))
            {
                break;
            }
        }
    }
    else
    {
        //目标值在后半段
        for (j = numsSize - 1; j > 0; j--)
        {
            if (nums[j] == target)
            {
                iRet = j;
                break;
            }

            if ((j - 1 >= 0) && (nums[j - 1] > nums[j]))
            {
                break;
            }
        }
    }
    return iRet;
}
```