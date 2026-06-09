```
void moveZeroes(int* nums, int numsSize)
{
    int count = 0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i] == 0)
        {
            count++;
            continue;
        }
        else
        {
            nums[i-count] = nums[i];
        }
    }
    for(int i = 0;i< count;i++)
    {
        nums[numsSize-1-i] = 0;
    }
}
```
