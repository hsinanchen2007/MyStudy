方法：顺次进行遍历，前后两项i和i+1逐个进行比较，j是更新时候num的数组下标，也是新数组中元素的个数值
int removeDuplicates(int* nums, int numsSize)
{
    int i=0,j=1;
    if(numsSize==0)  return 0;
    for(i=0;i<numsSize-1;i++)
    {
        if(nums[i+1]!=nums[i])
        {
            nums[j]=nums[i+1];
            j++;
        }
    }
    return j;
} 