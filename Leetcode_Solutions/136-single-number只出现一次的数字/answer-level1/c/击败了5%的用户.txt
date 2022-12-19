### 解题思路
此处撰写解题思路

### 代码

```c
int singleNumber(int* nums, int numsSize){
    int i,j;
    for(i=0;i<numsSize-1;i++)
        for(j=i+1;j<numsSize;j++){
            if(nums[j]!=-1&&nums[i]==nums[j]){
                nums[i]=-1;nums[j]=-1;
            }
        }
    for(i=0;i<numsSize;i++){
        if(nums[i]!=-1)
            return nums[i];
    }
    return -1;
}
```