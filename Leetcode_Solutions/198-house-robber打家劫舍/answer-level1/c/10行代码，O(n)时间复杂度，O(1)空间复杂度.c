### 解题思路
1、一次循环；
2、每次都计算走到此处的最优值；

时间复杂度：O(n);
空间复杂度：O(1),声明了一个局部变量max。

![无标题.jpg](https://pic.leetcode-cn.com/682f7f9e21d98d98c52fa79d2757b92167ce39bf499e2845d77cafc2d64fe84b-%E6%97%A0%E6%A0%87%E9%A2%98.jpg)


### 代码

```c
int rob(int* nums, int numsSize){
    if(numsSize<=0)return 0;
    if(numsSize==1)return nums[0];
    if(numsSize==2)return nums[0] > nums[1] ? nums[0] : nums[1];
    nums[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    int max = nums[1];
    for(int i=2;i<numsSize;i++){
        nums[i] = nums[i] + nums[i-2] > nums[i-1] ? nums[i] + nums[i-2] : nums[i-1];
        max = max > nums[i] ? max : nums[i];
    }
    return max;
}
```