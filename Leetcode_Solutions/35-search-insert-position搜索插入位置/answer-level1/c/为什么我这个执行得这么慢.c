### 解题思路
从插入排序里面提取了查找插入位置的算法；
有个问题 为什么要加入最后的判断语句呢？

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int low=0,high=numsSize-1,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) high=mid-1;
        else low=mid+1;
    }
    if(nums[mid]<target) return mid+1;
    else return mid;
}
```
### 总结
因为/2这个是向下取整的。