### 解题思路
先排序，再从左往右遍历，如果nums[j]-nums[i]>k，那么j之后的也不用再尝试了，直接break；如果nums[j]-nums[i]==k，那么个数加一，j之后的也不用尝试，break；如果num[i]在之前已经使用过，那么直接continue跳过，避免重复计算！

### 代码

```c
int cmp(const void* a, const void* b)
{
    return *(int *)a - *(int *)b;
}
int findPairs(int* nums, int numsSize, int k){
    int cnt = 0;
    if(numsSize<2)
        return 0;
    qsort(nums,numsSize,sizeof(int),cmp);//排序
    int temp = nums[0] - 1;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==temp)
            continue;
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[j]-nums[i]>k)//后面比nus[j]还大，不可能符合条件
                break;
            if(nums[j]-nums[i]==k)//后面比nus[j]还大，不可能符合条件
            {
                cnt++;
                break;
            }
        }
        temp = nums[i];
    }
    return cnt;
}
```