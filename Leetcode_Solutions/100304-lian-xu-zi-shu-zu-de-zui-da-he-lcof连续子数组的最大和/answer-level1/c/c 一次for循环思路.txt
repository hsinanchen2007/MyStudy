### 解题思路
一次for循环即可：

先初始化一个最大值 ans = nums[0]
然后进入for循环

每一次循环都做两次次判断

    第一次判断，判断是否要继续上次的和往下加，或者放弃前面的和，重新开始累加
                判断是继续累加 还是 在当前位置重新开始累加的标准是：如果前面的和加上“我”比我还小，那就从“我”重新开始

    第二次判断；判断当前的和是否已经大于ans，如果是更新一下ans



时间复杂度O（N）
空间复杂度O（1）

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int ans = nums[0];
    int curSum = nums[0];
    for(int i = 1;i<numsSize;i++){
        if((curSum + nums[i]) < nums[i])   //如果前面的和加上“我”比我还小，那就从“我”重新开始
            curSum = nums[i];
        else
            curSum += nums[i];
        if(ans<curSum)
            ans = curSum;
    }
    return ans;
}
```