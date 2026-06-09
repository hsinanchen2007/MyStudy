### 解题思路
动态规划
抢了第i-1家：抢i-2家最多的钱+第[i]家的钱
没抢第i家：抢i-1家最多的钱

### 代码

```c
int rob(int* nums, int numsSize){
    if(nums==0||numsSize==0)return 0;
    if(numsSize==1)return nums[0];

    int* Max=(int*)malloc(sizeof(int)*numsSize);
    Max[0]=nums[0];
    Max[1]=nums[0]>nums[1]?nums[0]:nums[1];

    for(int i=2;i<numsSize;++i)
        Max[i]=Max[i-2]+nums[i]>Max[i-1]?Max[i-2]+nums[i]:Max[i-1];
    
    int result=Max[numsSize-1];
    free(Max);
    return result;
}
```