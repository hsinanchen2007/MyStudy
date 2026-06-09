### 解题思路
此处撰写解题思路

### 代码

```c
int findUnsortedSubarray(int* nums, int numsSize){
    int left=0,right=numsSize-1;
    int i,j,min,max;
    while(right>left && nums[left]<=nums[left+1]) left++;
    while(right>left && nums[right]>=nums[right-1]) right--;
    if(left==right) return 0;
    min=nums[left];
    max=nums[right];

//  找到数组中的最大值和最小值
    for(i=left;i<=right;i++){
        if(nums[i]<min) min=nums[i];
        if(nums[i]>max) max=nums[i];
    }

    left=0,right=numsSize-1;
    while(nums[left]<=min) left++;
    while(nums[right]>=max) right--;

    return right-left+1;
}
```