**二分查找（注意细节！！！）**
```
/*寻找左边界*/
int lower_bound(int *nums, int numsSize, int target)
{
    int low = 0, high = numsSize, mid;
    while(low < high){                 //high = numsSize,故不带=
        mid = low + (high - low) / 2;       //避免溢出
        if(nums[mid] == target)
            high = mid;                 //为了找到左边界，相等时不立即返回
        else if(nums[mid] < target)
            low = mid + 1;          //左闭右开
        else
            high = mid;
    }
    if(low == numsSize)            //都比target小
        return -1;
    return nums[low] == target ? low : -1; 
}

/*寻找右边界*/
int upper_bound(int *nums, int numsSize, int target)
{
    int low = 0, high = numsSize, mid;
    while(low < high){                  //high = numsSize,故不带=
        mid = low + (high - low) / 2;   //避免溢出
        if(nums[mid] == target)
            low = mid + 1;        //为了找到右边界，相等时不立即返回，注意左闭右开
        else if(nums[mid] < target)
            low = mid + 1;          //左闭右开
        else
            high = mid;
    }
    if(high == 0)       //都比target大
        return -1;
    /*对low的更新是low = mid + 1, 所以mid = low - 1*/
    /*循环结束时low = high, nums[high] != target，　而nums[high-1]可能等于target*/
    return nums[high - 1] == target ? (high - 1): -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *p = (int*)malloc(sizeof(int) * 2);
    p[0] = -1;
    p[1] = -1;
    if(!nums || numsSize == 0)
        return p;
    p[0] = lower_bound(nums, numsSize, target);
    p[1] = upper_bound(nums, numsSize, target);
    return p;
}
```