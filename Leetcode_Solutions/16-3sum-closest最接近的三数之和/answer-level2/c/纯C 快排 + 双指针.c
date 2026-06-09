```
int CompareByIncrease(const void* a, const void* b)
{
    return *(int*)a - *(int*)b; // 快排构造递增序列
}

int threeSumClosest(int* nums, int numsSize, int target){
    int offset = INT_MAX; // 假设离目标值偏移量为最大初始值
    int temp = 0; // 临时偏移量
    int cur = 0;
    int low = cur + 1;
    int high = numsSize - 1;
    
    qsort(nums, numsSize, sizeof(int), CompareByIncrease);
    
    for(cur = 0; cur <= numsSize - 3; cur++)
    {
        low = cur + 1;
        high = numsSize - 1;
        
        while(low < high)
        {
            temp = nums[cur] + nums[low] + nums[high] - target;
            offset = ( abs(temp) < abs(offset) ) ? temp : offset;
            
            if(temp > 0)
            {
                high--;
            }
            else if(temp < 0)
            {
                low++;
            }
            else
            {
                return target;
            }  
        }
    }
    
    return target + offset;
}
```
