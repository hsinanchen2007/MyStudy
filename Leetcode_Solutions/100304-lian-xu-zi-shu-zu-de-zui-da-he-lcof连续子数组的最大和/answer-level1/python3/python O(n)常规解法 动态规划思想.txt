### 解题思路
    ex： [1,-2,3,10,]

    流程：
        ①初始化全局最大值max_pre = nums[0]，当前最大值max_sum=0
        ②当前最大值max_sum小于0时，置为当前值j。在大于0时，继续向后相加，寻找更大的值
        ③全局最大值max_pre 表示连续子数组和的最大值。目的为存储与输出


### 代码

```py
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum,max_pre = 0,nums[0] 
        #max_sum初值只要<=0皆可，目的是在第一论循环中max_sum = j
        for j in (nums):
            if max_sum < 0 :
                max_sum = j
            else:
                max_sum += j
            if max_pre < max_sum:
                max_pre = max_sum
        return max_pre
```