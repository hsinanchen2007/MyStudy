
### 解题思路
累加 -> 为负时，重新累加
### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int max = nums[0], cnt = nums[0];
    int i;
    for( i=1 ; i<numsSize ; i++)
    {
        if(cnt<0) cnt = nums[i];
        else cnt += nums[i];
        if(max < cnt) max = cnt;
    }
    return max;
}
```