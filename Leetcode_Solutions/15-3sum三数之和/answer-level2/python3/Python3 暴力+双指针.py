#### 理解题目

```
# 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复
# 的三元组。 
# 
#  注意：答案中不可以包含重复的三元组。 
# 
#  
# 
#  示例： 
# 
#  给定数组 nums = [-1, 0, 1, 2, -1, -4]，
# 
# 满足要求的三元组集合为：
# [
#   [-1, 0, 1],
#   [-1, -1, 2]
# ]
#  
#  Related Topics 数组 双指针

```
理解：a+b+c=0,且 返回的结果中不能包含重复的三元组

#### 解题思路
* 法1：暴力破解
* 法2：排序+双指针

#### 法1
```Python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # 法1 暴力破解 a + b + c
        res = []
        for i in range(len(nums) - 2):
            for j in range(i + 1, len(nums) - 1):
                for k in range(j + 1, len(nums)):
                    if nums[i] + nums[j] + nums[k] == 0:
                        res.append(tuple(sorted((nums[i], nums[j], nums[k]))))
        return list(set(res))
```
##### 复杂度分析
* 时间复杂度:O(n^3)
* 空间复杂度:O(1)

#### 法2

```Python
# 法2：排序+ 双指针遍历 a,b,c  对应指针 --> i, j ,k
        nums.sort()
        res = []
        for i in range(len(nums) - 2):
            if nums[i] > 0: break  # 跳过不可能情况
            if i > 0 and nums[i - 1] == nums[i]: continue  # 跳过连续一样的组合
            j, k = i + 1, len(nums) - 1
            while j < k:
                target = nums[i] + nums[j] + nums[k]
                if target < 0:
                    j += 1
                    while j < k and nums[j] == nums[j - 1]: j += 1  # 跳过连续一样的数
                elif target > 0:
                    k -= 1
                    while j < k and nums[k] == nums[k + 1]: k -= 1  # 跳过连续一样的数
                else:
                    res.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                    while j < k and nums[j] == nums[j - 1]: j += 1  # 跳过连续一样的数
                    while j < k and nums[k] == nums[k + 1]: k -= 1  # 跳过连续一样的数
        return res
```
##### 复杂度分析
* 时间复杂度:O(n^2)
* 空间复杂度:O(1)
