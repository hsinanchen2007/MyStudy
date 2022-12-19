### 解题思路
根据题目我们得知众数是超过一半的数字，那么根据这条规则我们只要对数组进行排序然后取出n/2处的值那必然就是众数；

### 代码

```c
int comp(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}
int majorityElement(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),comp);
    return nums[numsSize/2];
}

```