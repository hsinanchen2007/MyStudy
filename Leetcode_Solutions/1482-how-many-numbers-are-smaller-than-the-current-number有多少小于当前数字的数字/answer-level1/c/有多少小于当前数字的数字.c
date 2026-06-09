### 解题思路

c语言，while双层循环遍历

### 代码
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int* retResult = (int*)calloc(numsSize, sizeof(int));
    int i=0,j=0,count=0,counter;
    while(i<numsSize){
        count=0;
        counter = nums[i];
        j=0;
        while(j<numsSize){
            if(nums[j]<counter)count++;
            j++;
        }
        retResult[i]=count;
        i++;
    }
    *returnSize=numsSize;
    return retResult;
}
```