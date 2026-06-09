最基础的问题搞了好长时间，过程中遇到的问题分享下：
1、操作符的优先级问题>> + ,为避免这种，直接加括号，算是编程规范的问题吧
2、找不到值，跳出循环后，注意该返回mid还是mid+1
```
int searchInsert(int* nums, int numsSize, int target){
    
    int left = 0;
    int right = numsSize-1;
    int mid;
    while(left <= right){
        mid = left + ((right -left)>>1);
        if(nums[mid] == target)
        {
            return mid;
        }else if(target < nums[mid]){
            right = mid-1;
        }else if(target > nums[mid]){
            left = mid+1;
        }
    }

    if(target <nums[mid]){
        return mid;
    }else{
        return mid+1;
    }
}
```
