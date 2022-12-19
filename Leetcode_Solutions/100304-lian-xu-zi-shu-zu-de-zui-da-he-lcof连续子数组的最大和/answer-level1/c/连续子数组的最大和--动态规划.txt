### 解题思路
子数组（一个或连续多个整数组成）
当前面的连续子数组会对后面的子数组有负面影响，则截断之前的连续子数组；
否则，应该使前面的连续子数组扩展至当前的子数组
### 代码

```c
#define max(a,b) a+b<a?a:a+b

int maxSubArray(int* nums, int numsSize){
    int result;
    int tool;
    result=tool=nums[0];
    for(int i=1;i<numsSize;i++){
        tool=max(nums[i],tool);
        result=tool<result?result:tool;
    }
    return result;
}


```