### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
int i,j,count=0;
int*ret=(int*)malloc(sizeof(int)*numsSize);
for(i=0;i<numsSize;i++){
    for(j=0;j<numsSize;j++){
    if(nums[i]>nums[j])
    count++;
    }
    ret[i]=count;
    count=0;
}
*returnSize=numsSize;
return ret;
}
```