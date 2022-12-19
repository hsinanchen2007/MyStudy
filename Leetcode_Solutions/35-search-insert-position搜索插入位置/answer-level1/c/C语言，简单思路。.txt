### 解题思路
![image.png](https://pic.leetcode-cn.com/78658a0419132dc90218803e89bd019010fc1eae45faeafe5ad2e3fd6a2397b7-image.png)


考虑两个极端：
大于最大的数，返回numsize，此处不能等于。
小于等于最小的数，返回0。

然后与最中间的数字进行比较。
大于等于时，说明在前半部分。搜索查找。
小于时，说明在后半部分。搜索查找。

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    if(numsSize==0)
    {
        return 0;
    }
    if(nums[0]>=target)
    {
        return 0;
    }
    if(nums[numsSize-1]<target)//可能存在 1 2 2 2 2 这种情况。
    {
        return numsSize;
    }
    int i,middle=nums[numsSize/2];
    if(middle>=target)
    {
        for(i=0;i<numsSize/2+1;i++)
        {
            if(nums[i]==target)
            {
                return i;
            }
            else if(nums[i]<target&&nums[i+1]>target)
            {
                return i+1;
            }
        }
    }
    else
    {
        for(i=numsSize/2;i<numsSize;i++)
        {
            if(nums[i]==target)
            {
                return i;
            }
            else if(nums[i]<target&& nums[i+1]>target)
            {
                return i+1;
            }
        }
    }
    return 0;

}
```