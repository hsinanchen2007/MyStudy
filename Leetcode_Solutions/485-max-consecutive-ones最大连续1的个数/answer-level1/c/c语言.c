### 解题思路
双循环

### 代码

```c
int findMaxConsecutiveOnes(int* nums, int numsSize){
    int max=0;
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
            if((end-start)>max)
            max=(end-start);
        }
    }
    return max;
}
```