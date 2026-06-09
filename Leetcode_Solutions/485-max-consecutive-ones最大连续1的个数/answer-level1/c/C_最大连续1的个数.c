### 解题思路
max记录最大值，sum记录连续的1的个数，每数完一串1，就跟新sum
### 代码

```c
int findMaxConsecutiveOnes(int* nums, int numsSize){
    int max=0,sum=0;
    for(int i=0;i<numsSize;++i)
        if(nums[i]==1)
            ++sum;
        else
        {
            max=max>sum?max:sum;
            sum=0;
        }
    return max>sum?max:sum;
}
```