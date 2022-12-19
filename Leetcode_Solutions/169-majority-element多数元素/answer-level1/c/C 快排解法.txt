### 解题思路
给数组排序，中位数就是多数元素。采用快速排序，判断新基准值的位置选定下一次快排的边界，知道基准值落在n/2

### 代码

```c
int majorityElement(int* nums, int numsSize){
    //快速排序
    int low=0,high=numsSize-1,mid=0;
    while(mid!=numsSize/2) {
        mid=quickSort(nums,low,high);
        if(mid<numsSize/2) low=mid+1;
        else if(mid>numsSize/2) high=mid-1;
    }
    return nums[mid];
}

int quickSort(int* nums,int low,int high){//一次快速排序
    int base=nums[low];
    while(low<high) {
        while(low<high && base<nums[high]) high--;
        if(low<high) nums[low++]=nums[high];
        while(low<high && base>nums[low]) low++;
        if(low<high) nums[high--]=nums[low];
    }
    nums[low]=base;
    return low;
}
```