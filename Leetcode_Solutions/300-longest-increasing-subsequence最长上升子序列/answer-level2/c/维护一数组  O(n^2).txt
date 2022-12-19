### 解题思路
此处撰写解题思路

### 代码

```c
int lengthOfLIS(int* nums, int numsSize){
int*hope=(int*)malloc(sizeof(int)*numsSize);
int i,j,cur,max;
if(numsSize==0)
return 0;
for(i=numsSize-1;i>-1;i--)
{
    max=1;
    for(j=i+1;j<numsSize;j++)
    {
        if(nums[j]>nums[i])
        {
            cur=hope[j]+1;
            if(max<cur)
               max=cur;
        }
    }
    hope[i]=max;
}
for(i=0,max=0;i<numsSize;i++)
if(hope[i]>max)
 max=hope[i];
 return max;
}
```