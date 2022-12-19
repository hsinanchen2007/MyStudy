先对数组排序，冒泡排序长度较大时效率低，选用快速排序法
注意有两个及以上负数的情况，最大值有可能是nums[0] * nums[1] * nums[numsSize - 1];
```
void qusort(int* arr, int left, int right)
{
    int mid = left;
    int fless = right;
    int base = arr[left];
    if(left < right)
    {
        while(mid < fless)
        {
            while(mid<fless && arr[fless] >= base)
            {
                fless--;
            }
            if(mid < fless)
            {
                arr[mid] = arr[fless];
                mid++;
            }

            while(mid<fless && arr[mid] < base)
            {
                mid++;
            }
            if(mid < fless)
            {
                arr[fless] = arr[mid];
                fless--;
            }
        }   
        
        arr[mid] = base;
        qusort(arr,left,mid - 1);
        qusort(arr,mid + 1, right);
    }
    return;
}
int maximumProduct(int* nums, int numsSize)
{   
    qusort(nums,0,numsSize - 1); //快速排序
    int max = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    if(nums[1] < 0)
    {
        int m = nums[0] * nums[1] * nums[numsSize - 1];
        max = (m > max) ? m : max;
    }
    return max;
}
```
