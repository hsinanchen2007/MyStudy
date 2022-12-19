### 解题思路
常规思路

### 代码

```c
int findMaxConsecutiveOnes(int* nums, int numsSize){
    int* num=(int*)calloc(sizeof(int),numsSize);
    int n=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==1)
        {
            int start=1,end=2;
            for(int j=i+1;j<numsSize;j++)
            {
                if(nums[j]==1)
                {
                    end++;
                }
                else
                {
                    break;
                }
            }
            num[n++]=(end-start);
        }
    }
    int max=num[0];
    for(int j=1;j<n;j++)
    {
        if(num[j]>max)
        {
            max=num[j];
        }
    }
    return max;
}
```