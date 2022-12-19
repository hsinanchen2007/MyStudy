解法一： 暴力求解，3个for循环，时间复杂度$O(n^3)$
解法二： 排序+双指针法，见精选题解，时间复杂度$O(nlogn)+O(n^2)$
解法三： 排序+边界法


解法三是介于解法一和解法二之间的，逻辑思路更简单，复杂度不稳定
1. 排序，复杂度 $O(nlogn)$
2. 由于数组有序，三数之和实际上递增，三数之和与taget的距离由负数到正数，那么最小距离一定在距离为0的边界上，当距离为正数后即可跳出本轮循环


```
def threeSumClosest(nums, target):
    if len(nums) < 3:
        return ''
    min_dis = 1e6
    three_sum = 0
    nums = sorted(nums)
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            for k in range(j + 1, len(nums)):
                dis = nums[i] + nums[j] + nums[k] - target
                if dis >= 0:
                    if dis < min_dis:
                        min_dis = dis
                        three_sum = dis + target
                    break
                else:
                    if -dis < min_dis:
                        min_dis = -dis
                        three_sum = dis + target
    return three_sum


```
