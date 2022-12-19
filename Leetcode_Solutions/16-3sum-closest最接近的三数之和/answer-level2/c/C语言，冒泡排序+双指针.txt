
void BubbleSort(int* nums, int numsSize)
{
    int i,j;
    int tmp = 0;
    
    for(i=0; i<numsSize-1;i++)
    {
        for(j = 0;j<numsSize-i-1;j++)
        {
            if(nums[j]>nums[j+1])
            {
                tmp = nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=tmp;
            }
        }
    }
    return;
}

#define min(a,b) a<b?a:b
#define abs(a,b) a<b?(b-a):(a-b)

int threeSumClosest(int* nums, int numsSize, int target)
{
    if((numsSize < 3) || (nums == NULL))
    {
        return 0;
    }
    
    BubbleSort(nums,numsSize);
    
    int i,right,left;
    int oneThreeSum = 0;
    int oneSumGap = 0;
    int minSumGap = 0x0FFFFFFF;
    int minThreeSum = 0;
    
    for (i=0;i<numsSize-2;i++)
    {
        left = i+1;
        right = numsSize-1;
        while(right-left >= 1)
        {
            oneThreeSum = nums[i]+nums[left]+nums[right];
            oneSumGap = abs(oneThreeSum,target);
            if(oneSumGap==0)
            {
                return target;
            }
            if(oneSumGap < minSumGap)
            {
                minSumGap = oneSumGap;
                minThreeSum = oneThreeSum;
            }
            
            if(oneThreeSum>target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    return minThreeSum;
}

