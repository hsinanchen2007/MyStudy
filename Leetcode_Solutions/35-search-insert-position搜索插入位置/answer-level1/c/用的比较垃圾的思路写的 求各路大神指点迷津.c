### 解题思路
此处撰写解题思路

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int k=0;
    int i=0;
    for(i=0;i<numsSize;i++){
        if(nums[i]<target){
            k=k+1;
        }
        else if(nums[i]>=target){
            return k;
        }
    }
    return k;
}
```