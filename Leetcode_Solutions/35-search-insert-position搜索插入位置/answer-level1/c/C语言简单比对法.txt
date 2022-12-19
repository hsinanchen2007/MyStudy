### 解题思路

解题思路就是最容易想到的常规思路。
结尾的“return 0;”总是漏掉报错……

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    for(int i=0;i<numsSize;i++){
        if(nums[i]==target){
            return i;
        }
    }
    if(target<nums[0]) return 0;
    if(target>nums[numsSize-1]) return numsSize;
    for(int i=0;i<numsSize;i++){
        if(target>nums[i] && target<nums[i+1]) return i+1;
    }
    return 0;
}
```