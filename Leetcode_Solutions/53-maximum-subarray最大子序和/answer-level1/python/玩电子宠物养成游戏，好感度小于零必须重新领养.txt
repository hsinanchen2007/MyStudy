### 解题思路
假设一个电子宠物养成游戏，每小时会统计，随机增加或降低宠物好感度，初始好感度随机，任何时候（包括初始值）好感度降到0以下（sum_sub<0），必须重新领养一只（sum_sub=0）。后面只要不出现好感度降为负数的情况，这只宠物的好感度就会继续累加，游戏会记录你曾经达到过的最高好感度（max_sum_sub）。
### 代码
```python
''' nums        -2,     1, -3,      4, -1, 2, 1, -5, 4
    sum_sub(>0) -2->0,  1, -2->0,   4,  3, 5, 6, 1,  5
    max_sum_sub -2,     1, 1,       4,  4, 5, 6, 6,  6
'''
class Solution(object):
    def maxSubArray(self, nums):
        # sum_sub represent for the short sub which will be set to 0 if it acutally < 0
        sum_sub = max(0, nums[0])
        # max_sum_sub is always rising
        max_sum_sub = nums[0]
        for i in range(len(nums)-1):
            sum_sub += nums[i+1]
            max_sum_sub = max(nums[i+1], sum_sub, max_sum_sub)
            if sum_sub < 0:
                sum_sub = 0
        return max_sum_sub
```