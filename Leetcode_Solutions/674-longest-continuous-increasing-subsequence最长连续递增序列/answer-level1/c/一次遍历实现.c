**sum用来记录连续递增的长度，递增中断时与max比较后重置sum**
int findLengthOfLCIS(int* nums, int numsSize)
{
    if (numsSize == 0)
    {
        return 0;
    }   
    int i = 0, sum = 1, max = 1;  
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            sum++;
        }
        else 
        {
            if (sum > max)
            {
                max = sum;
            }         
            sum = 1;
        }
    }    
    //整个数组都是递增的情况
    if (sum > max)    
    {
        max = sum;
    }

    return max;
}
