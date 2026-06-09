### 解题思路
累加法，max记录最大的累加数据，cnt记录一段的累加数据，当一段的累加数据小于0时，放弃这一段，继续往后累加

### 代码

```c
int maxSubArray(int* nums, int numsSize){
int max = -INT_MAX;int cnt = 0;
for(int i =0;i < numsSize;i++){
    cnt += nums[i];
    if(cnt > max)max = cnt;
    if(cnt < 0)cnt = 0;
}return max;
}
```