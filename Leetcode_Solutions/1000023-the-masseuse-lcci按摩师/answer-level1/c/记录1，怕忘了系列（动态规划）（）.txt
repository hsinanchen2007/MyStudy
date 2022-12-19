**思路方法：**
1、第一种我想的是递归的方法，但是是超时的，
    2,1,4,5,6,1,1,3
选2，从4开始递归[4,5,6,1,1,3] 或者从5开始递归[5,6,1,1,3]  ==>> 比较递归的结果，大的加上第一个值2
得到 k1

不选2，从1开始递归[1,4,5,6,1,1,3] ==>> 得到结果 k2

然后 return k1 > k2 ? k1 : k2;

代码如下
```
int massage(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    else if (numsSize == 1) return *nums;
    else if (numsSize == 2) return nums[0] > nums[1] ? nums[0] : nums[1];

    int k1 = nums[0], k2;
    int t1 = massage(nums + 2, numsSize - 2), t2 = massage(nums + 3, numsSize - 3);
    k1 += t1 > t2 ? t1 : t2;
    k2 = massage(nums + 1, numsSize - 1);
    return k1 > k2 ? k1 : k2;

}
```

2、动态规划
考虑第i预约， 如果接i    结果就只能是前(i - 1)不接所获得的预约 + 第i次预约时间 ==>> 得到第i预约的总时长
             如果不接i，那么第i预约的总时长就是max(接(i-1)， 不接(i-1))


代码如下
```
int massage(int* nums, int numsSize){
    if (numsSize == 0) return 0;

    int dp0 = 0;      //不接
    int dp1 = nums[0];//接

    for (int i = 1; i < numsSize; ++i)
    {
        int t_dp0 = dp0 > dp1 ? dp0 : dp1;   //不接第i个
        int t_dp1 = dp0 + nums[i];           //接第i个

        dp0 = t_dp0;
        dp1 = t_dp1;
    }

    return dp0 > dp1 ? dp0 : dp1;
}

```

