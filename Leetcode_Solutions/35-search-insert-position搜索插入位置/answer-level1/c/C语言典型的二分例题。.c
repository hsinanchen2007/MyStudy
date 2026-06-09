### 解题思路
二分就vans了。
### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int l =0, r= numsSize-1,mid;
    while(l<=r){
        mid = (l+r)/2;
        if(target >nums[mid])
            l = mid + 1;
        else if(target < nums[mid])
            r = mid - 1;
        else
            return mid;
    }
    return target > nums[mid] ?
            mid+1 :mid; 
}
```