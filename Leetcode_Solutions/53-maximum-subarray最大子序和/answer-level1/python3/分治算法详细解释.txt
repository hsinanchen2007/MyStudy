看了很久分治算法才看懂，写下来比较好理解。
算法思路：
第一步：把大问题分解成和原来问题性质一样的小问题
第二步：利用递归解决小问题
第三步：找到小问题合并转化为大问题的方法
思路很简单，但是没有例子不好理解。
结合这个题具体来说：
```
import numpy as np
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 1 :
            return nums[0]
        else :

    #第一步：这个问题要求一个数组nums的最大子数组，我们可以把这个数组分成两半：
    #前一半叫left_nums,后一半叫right_nums。
    #最大子数组有三种可能存在的形式：
    #1.完全位于左半数组，2.完全位于右半数组，3.贯穿左右两个数组（这个比较难理解，在后面将会解释）
    #（形式1和形式2是和原问题性质相同但规模更小的小问题，形式3是需要解决的新的小问题）
            left_nums = nums[:len(nums)//2]
            right_nums = nums[len(nums)//2:]

    #第二步：形式1和形式2要求left_nums和right_nums的最大子数组，解法与求nums的最大子数组一样，
    #所以可以用递归解决，即引用该函数。
            max_left = self.maxSubArray(left_nums)
            max_right = self.maxSubArray(right_nums)
    
    #此处要详细解释 形式3.求贯穿左右两个数组的最大子数组的计算方法：从中间往两边算，然后把结果相加
        #1）从右往左算left_nums的连续最大子数组，所以计算出来的子数组一定在右边粘连右半数组。
            tmp = 0
            max_l = left_nums[-1]
            for i in range(len(left_nums)-1,-1,-1) :
                tmp += left_nums[i]
                max_l = max(max_l, tmp)
        #2）从左往右算right_nums的连续最大子数组，所以计算出来的子数组一定在左边粘连左半数组。
            tmp = 0
            max_r = right_nums[0]
            for i in range(len(right_nums)) :
                tmp += right_nums[i]
                max_r = max(max_r, tmp)
        #形式3的结果即为max_r+max_l
    
    #第三步：取形式1/2/3结果中的最大值，即可得到整个数组的最大子数组的和。
            re = max(max_left, max_right, max_r + max_l)
            return re
```


