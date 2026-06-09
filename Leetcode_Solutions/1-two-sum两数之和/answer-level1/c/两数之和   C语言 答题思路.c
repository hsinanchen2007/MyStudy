### 直接比较
将原数组中的数两两比较，
当两数相加等于目标数时，
返回这两个数的下标

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

int i,j;
int *result=NULL;
*returnSize=2;
result=(int*)malloc(2*sizeof(int));

for(i=0;i<numsSize;i++)
{
    for(j=i+1;j<numsSize;j++)
    {
        if(nums[i]+nums[j]==target)
        {
            result[0]=i;
            result[1]=j;
            return result;
        }
    }
}
return result;

}


```