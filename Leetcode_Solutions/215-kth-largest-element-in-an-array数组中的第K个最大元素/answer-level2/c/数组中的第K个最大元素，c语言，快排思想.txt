### 解题思路
利用快排的思想。但是枢纽每次都选的第一个，结果就很慢...
1. 如果让求前k小/大元素的排序，可以用简单选择、冒泡、堆，当k≥5时用堆最好，因为建堆的比较次数不超过4n。
2. 如果让求第k个最大/小的元素，用快排的思想，但是快排总是选第一个元素当枢纽的办法并不很好。
### 代码

```c
int partition(int* nums,int low,int high,int k){
    int pivot = nums[low],i=low,j=high;
    while(low<high){
        while(low<high && nums[high]<=pivot) high--;
        nums[low] = nums[high];
        while(low<high && nums[low]>=pivot) low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    if(low == k-1){
        return nums[low];
    }else if(low < k-1){
        return partition(nums,low+1,j,k);
    }else{
        return partition(nums,i,low-1,k);
    }
}
int findKthLargest(int* nums, int numsSize, int k){
    return partition(nums,0,numsSize-1,k);
}
```