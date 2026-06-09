### 解题思路
此处撰写解题思路

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int i;
    for(i=0;i<numsSize;i++){
        if(nums[i]<target) continue;
        else break;
    }
    return i;
}
```