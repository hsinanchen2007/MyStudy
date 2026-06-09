思路重点：
    

1. 首先解读清楚题目需求，找到中心索引，条件为中心点的左边总和等于右边的总和。即数据可以
分为左边总和，中心点，右边总和。而这三部分之和就是数据的总和。
2. 可以得出公式sum_right = sum_nums - sum_left - mediam_point
3. 遍历数组，将mediam_point赋值为当前的遍历的数值
4. 如果出现sum_left = sum_nums - sum_left - mediam_point的值，即可推断出sum_right = sum_left。return当前的数组下标值。
5. 如果遍历结束，没有出现满足等式的情况，return -1.


```
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        sum_nums,sum_left = sum(nums),0
        for i in range(len(nums)):   
            if sum_left == sum_nums - sum_left - nums[i]:return i   
            sum_left += nums[i]
        return -1
```
            