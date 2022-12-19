
**1、遍历查找**
简单易用，时间复杂度O(n)
```
int searchInsert(int* nums, int numsSize, int target){
    for(int i=0;i<numsSize;i++){
        if(nums[i] >= target) return i;
        if(i+1 == numsSize) return numsSize;
    }
    return 0;
}
```

**2、二分查找法**
大数据量时效率高，时间复杂度O(logn)
```
int searchInsert(int* nums, int numsSize, int target){
    int left=0,right=numsSize-1,mid;
    while(left<=right){
        mid = (left+right)/2;
        if(nums[mid]<target) left = mid+1;
        else if(nums[mid]>target) right = mid-1;
        else return mid;
    }
    return left;
}
```

