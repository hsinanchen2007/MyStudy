### 解题思路
就是hash表的应用

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize){
    int *hash_count=(int *)malloc(sizeof(int)*numsSize);//hash表，存个数
    int *hash_num=(int *)malloc(sizeof(int)*numsSize);//hash表，存元素
    memset(hash_count,0,sizeof(int)*numsSize);

    int i;
    for(i=0;i<numsSize;i++)
    {
        int target=nums[i];
        if(nums[i]<0)
            target=-target-1;
        while(hash_num[target%numsSize]!=nums[i]&&hash_count[target%numsSize]!=0)//位置为空
        {
            target++;
        }
        hash_num[target%numsSize]=nums[i];
        hash_count[target%numsSize]++;
    }
    int *result=(int *)malloc(sizeof(int)*numsSize);
    int index=0;
    for(i=0;i<numsSize;i++)
    {
        if(hash_count[i]>numsSize/3)//符合要求
        {
            result[index++]=hash_num[i];
        }
    }
    *returnSize=index;
    return result;
}
```