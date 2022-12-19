### 解题思路
数组发生旋转，数组就变为一个升序+另一个升序，中间存在一个变化点，比如34512(变化的在5 1处)
1.如果数组未旋转，那么nums[l]一定小于nums[r]，直接返回nums[l]；
2.如果数组旋转，那么nums[l]>nums[r]，判断nums[mid]和nums[r]的大小
3.如果nums[mid]<nums[r]，所以[mid,r]升序，最小值一定在左半部分,right = mid;(mid可能也是最小值)
4.如果nums[mid]>nums[r]，又根据2知道nums[l]>nums[r],数组在[l,mid]升序，所以最小值一定在右半部分,left = mid + 1；

### 代码

```c
int findMin(int* nums, int numsSize){
    int left=0;
    int right=numsSize-1;
    while(right>left)
    {
        int mid=left+(right-left)/2;
        if(nums[mid]>nums[right])
            left=mid+1;
        else
            right=mid;
    }
    return nums[left];
}
```