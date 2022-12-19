### 解题思路
要考虑到有3种情况
1. 出现在中间 [0,1,2,4,5]
2. 出现在边缘 [1,2,3] [0,1,2,4]
3. 全部符合，返回的是 numsSize
因为是升序，所以当nums[mid]==mid时，表示mid前面的顺序没有问题，
当nums[mid]>mid时，证明问题就出在mid或者mid的前面
### 代码

```c
int missingNumber(int* nums, int numsSize){
    int left=0,right=numsSize-1,mid;
    while(left<right){
        mid=(left+right)/2;
        if(nums[mid]==mid){
            left=mid+1;
        }
        else if(nums[mid]>mid){
            right=mid;
        }
    }
    if(nums[left]==left)
        return numsSize;
    else return left;
}
```