### 解题思路
动态数据规划a[0]=nums[0];a[1]=nums[1];a[2]=nums[0]+nums[2]
状态转移方程
numsSize=0; maxsum=0;
numsSize=1;maxsum=nums[0];
numsSize=2;maxsum=MAX(nums[0],nums[1]);
numsSize=3;maxsum=MAX(nums[0]+nums[2],nums[1]);
numsSize>=4;maxsum=MAX(nums[i]+a[i-2],nums[i]+a[i-3]);

### 代码

```c
#define MAX(a,b)  (a>b?a:b)
int rob(int* nums, int numsSize)
{
int i;
int*a=(int*)malloc(sizeof(int)*numsSize);
if(numsSize==0) return 0;
if(numsSize==1) return nums[0];
if(numsSize==2) return MAX(nums[0],nums[1]);
if(numsSize==3) return MAX((nums[0]+nums[2]),nums[1]);
a[0]=nums[0];a[1]=nums[1];a[2]=nums[0]+nums[2];
for(i=3;i<numsSize;i++)
    {
        a[i]=MAX(nums[i]+a[i-2],nums[i]+a[i-3]);
    }
int maxsum=a[0];
i=1;
while(i<numsSize)
    {
        maxsum=a[i]>maxsum?a[i]:maxsum;
        i++;
    }
return maxsum;
}
```