### 解题思路
假设要寻找A[low..high]的最大子数组，采用分治策略，则可以将A[low..high]划分为两个规模尽量相等的子数组A[low..mid]，A[mid+1..high]，其中mid在A[low..high]的中间位置。可知，A[low..high]的最大子数组可能出现的位置为：
    - 完全位于A[low..mid]中
    - 完全位于A[mid+1..high]中
    - 跨越了中点
其中在A[low..mid]和A[mid+1..high]这两个位置可以直接继续递归就可以了，但跨越了中点需要从中点向两头搜索A[i..mid]，A[mid+1..j]（low<=i<=mid，mid<j<=high）这两个子数组就组成了原数组的一个最大子数组；



### 代码

```c
int FindMaxCorssSubarray(int *nums,int low,int mid,int high)
{
    int leftsum = INT_MIN;
    int sum = 0;
    int i;
    for(i=mid;i>=low;i--)
    {
        sum += nums[i];
        if(sum>leftsum)
            leftsum = sum;
    }
    int rightsum = INT_MIN;
    sum = 0;
    for(i = mid+1;i<=high;i++)
    {
        sum += nums[i];
        if(sum > rightsum)
            rightsum = sum;
    }
    return leftsum+rightsum;
}
int FindMaximumSubarray(int *nums,int low,int high)
{
    if(high == low)
        return nums[low];
    else
    {
        int mid = floor((low+high)/2);
        int leftsum = FindMaximumSubarray(nums,low,mid);
        int rightsum = FindMaximumSubarray(nums,mid+1,high);
        int crosssum = FindMaxCorssSubarray(nums,low,mid,high);
        if(leftsum >= rightsum && leftsum >=crosssum)
            return leftsum;
        else if(rightsum>=leftsum && rightsum>=crosssum)
            return rightsum;
        else
            return crosssum;
    }
}
int maxSubArray(int* nums, int numsSize){
    return FindMaximumSubarray(nums,0,numsSize-1);
}
```