### 解题思路
根据快速排序改编

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* exchange(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    int low=0,high=numsSize-1;
    while(low<high)
    {
        while(low<high&&nums[low]%2==1)++low;
        while(low<high&&nums[high]%2==0)--high;
        int temp=nums[low];
        nums[low]=nums[high];
        nums[high]=temp;
    }
    return nums;
}
```