我的动态规划思路（最近在学习动态规划，说的不对希望大佬指正）： 
从最后一步开始想： 
比如例子中：
nums = [2,7,9,3,1] 
如果最后一步是在nums[4]=1 为止，
那么为了使最后的结果最大，则前面取值之和必须最大，
又根据题设两次取值不能相邻，
所以有状态转移方程： 
F(4) = max(F(2),F(1),F(0)) + nums[4]. 
同理，F(2),F(1),F(0) 要取到各自最大，
则状态转移方程分别为: 
F(2) = max(F(0)) + nums[2] 
F(1) = nums[1] F(0) = nums[0] 
注意，还剩下一个nums[len(nums)-2] 没有转换，
例子中也就是F（3） F(3) = max(F(1),F(0)) + nums[3] 
所以，F（1）和 F（0） 需要设置初始条件即分别为:nums[1],nums[0]. 
如下代码： 
go语言实现 空间复杂度比较高，时间是100%
```
func rob(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    if len(nums) == 1 {
        return nums[0]
    } else if len(nums) == 2 {
        return int(math.Max(float64(nums[0]),float64(nums[1])))
    }

    maxValue := make([]int,len(nums))
    maxValue[0] = nums[0]
    maxValue[1] = nums[1]
    res := int(math.Max(float64(maxValue[0]),float64(maxValue[1])))
    for i:=2;i<len(nums);i++ {
        tmp := maxValue[i-2]
        for j:=i-3;j>=0;j--  {
            tmp = int(math.Max(float64(tmp),float64(maxValue[j])))
        }
        maxValue[i] = tmp + nums[i]
        if res < maxValue[i] {
            res = maxValue[i]
        }
    }
    return res
}
```
