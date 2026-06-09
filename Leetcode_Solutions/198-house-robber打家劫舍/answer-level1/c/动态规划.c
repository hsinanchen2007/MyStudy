### 解题思路
定义状态 a[i]为i次拿到的最高金额
初始条件为 a[0] = nums[0]; a[1] = max(nums[0], nums[1]);
状态转移方程
1. a[i]=a[i-1] 前一个选，i次不选
2. a[i]=a[i-2]+nums[i]前一个不选了，i次选
3. a[i]=max(a[i],a[i-2]+nums[i]);

### 代码

```c
int max(int a,int b){
    if(a > b)
        return a;
    else
        return b;
}
int rob(int* nums, int numsSize){
    if(numsSize < 1)
        return 0;
    if(numsSize == 1)
        return nums[0];
    int a[numsSize];
    a[0] = nums[0];
    a[1] = max(nums[0],nums[1]);
    for(int i = 2;i < numsSize;++i){
        a[i] = a[i - 1];
        a[i] = max(a[i],(a[i - 2] + nums[i]));
    }
    return a[numsSize - 1];
}
```