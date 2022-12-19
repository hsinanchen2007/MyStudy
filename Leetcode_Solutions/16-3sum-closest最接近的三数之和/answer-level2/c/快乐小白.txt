### 解题思路
简单粗暴

### 代码

```c
int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}


int threeSumClosest(int* nums, int numsSize, int target){
    int min=9999999;
    int sum;
    qsort(nums,numsSize,sizeof(nums[0]),cmp);
    for(int i=0;i<numsSize-2;i++)
    {
        printf("%d %d\n",i,nums[i]);
        int j=i+1;
        int z=numsSize-1;
        while(j<z)
        {
            int t=nums[i]+nums[j]+nums[z];
            if(min>abs(t-target))
            {
                sum=t;
                min=abs(t-target);
            }
            if(t-target>0)
            {
                z--;
            }
            if(t-target<0)
            {
                j++;
            }
            if(t-target==0)
            {
                return target;
            }
        }
    }
    return sum;
}
```