分治：最大子序和只出现在左侧、只出现在右侧、横跨左右侧三种情况。
```c
#define max(a,b)  (a>b ? a:b)
int maxSubArray(int* nums, int numsSize){
    int i = 0;
    int sum = 0;
    int max_left = 0,max_right = 0;
    int max_midleft = 0,max_midright = 0,max_mid =0;
    //1,结束条件
    if ((numsSize==0) || (numsSize==1)) return nums[0];  
    //2,递归求左右最大
    max_left = maxSubArray(&nums[0], numsSize / 2);
    max_right = maxSubArray(&nums[numsSize / 2], numsSize-numsSize / 2);
    //3,求横跨中间最大 以中间为起点 先左向最大后右向最大 最后左右求和减中间重复元素
    max_midleft = nums[numsSize / 2];
    for (i = numsSize / 2; i >= 0; i--){
        sum += nums[i];
        if (sum > max_midleft){
            max_midleft = sum;
        }
    }
    sum=0;
    max_midright = nums[numsSize / 2];
    for (i = numsSize / 2 ; i < numsSize; i++){
        sum += nums[i];
        if (sum > max_midright){
            max_midright = sum;
        }
    }
    max_mid=max_midleft + max_midright - nums[numsSize / 2];
    //4,三者比较返回最大值
    return max(max(max_left,max_right),max_mid);
}
```
动态规划：从左往右遍历，记录前面元素的累加。往右的过程中，如果遇到某个数大于累加和+此数，因为继续往后走后面的元素资源都一样，这时候原来以某个数为头的子序从此往后开始拖后腿了（但不能否认其曾经峰值的存在，以max记录），那么舍弃原来的和，以遇到的这个数为头建立新的子序。
```c
int maxSubArray(int* nums, int numsSize){
    int cursum= nums[0];
    int maxsum= nums[0];  
    for (int i = 1; i < numsSize; i++){
        cursum = (cursum+nums[i] > nums[i] ? cursum+nums[i] : nums[i]);
        if (cursum > maxsum) maxsum = cursum;
    }
    return maxsum;
}
```