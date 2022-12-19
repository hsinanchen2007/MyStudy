尝试写的第一个桶排序代码：
**STEP1**:生成一个长度为101的数组bucket，因为给的数的范围是0到100.
**STEP2**:让bucket中所有元素归零
**STEP3**：遍历给定的数组nums，nums[i]=j,就把bucket[j]++。相当于bucket是记录nums中每个数出现的次数。
**STEP4**：数数，小于nums[i]的数的个数就是bucket[nums[i]]前面所有元素的和
时间复杂度为O(N)
```
//用桶排序写写
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
int bucket[101];
int* ans=(int*)malloc(sizeof(int)*numsSize);
*returnSize=numsSize;
int i;
//桶里元素清零
for(i=0;i<101;i++)
{
    bucket[i]=0;
}
//往桶里装东西
for(i=0;i<numsSize;i++)
{
    bucket[nums[i]]++;
}

int sum=0,j=0;
for(i=0;i<numsSize;i++)
{
    for(j=0;j<nums[i];j++)
    {
        sum=sum+bucket[j];
    }
    ans[i]=sum;
    sum=0;
}
return ans;
}
```

 