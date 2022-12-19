### 解题思路
和打家劫舍相同，动态规划

### 代码

```c
int massage(int* nums, int numsSize){

    if(numsSize==0||nums==0)return 0;
    if(numsSize==1)return nums[0];

    int* result=(int*)malloc(sizeof(int)*numsSize);
    result[0]=nums[0];result[1]=nums[0]>nums[1]?nums[0]:nums[1];
    for(int i=2;i<numsSize;++i)
        result[i]=result[i-2]+nums[i]>result[i-1]?result[i-2]+nums[i]:result[i-1];
    
    int temp=result[numsSize-1];
    free(result);
    return temp;
    
}
```