### 解题思路
此处撰写解题思路

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j,*resultedArray=NULL;
    *returnSize=0;
    for (i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++){
            if (nums[i]+nums[j]==target)
            {
                resultedArray=(int*)malloc(sizeof(int)*2);
                resultedArray[0]=i;
                resultedArray[1]=j;
                *returnSize=2;
                return resultedArray;
            }
        }
    }
    return resultedArray;
}


```