### 解题思路
数组排序 + 双指针从两端向中间遍历
对于nums[i]，寻找它之后的俩数之和能否组成0 - nums[i]
寻找两数之和能否组成0 - nums[i]，用双指针从两端向中间遍历
如果和比预期小，低指针+1，如果和比预期大，高指针-1
如果和预期相等，需要判重
注意：如果nums长度小于3，直接返回结果
排序之后的数组，如果nums[i]为正数，那么它之后的数都比他大，不可能3数之和为0，直接返回结果
### 代码

```python
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        arr = []
        if len(nums) >= 3:
            nums = sorted(nums)

            for i in range(len(nums) - 2):
                # 排序之后的数组，如果nums[i]为正数，那么它之后的数都比他大，不可能3数之和为0
                if nums[i] > 0:
                    break

                # 跳过重复数据
                if nums[i] not in arr:
                    arr.append(nums[i])
                    lowp = i + 1
                    highp = len(nums) - 1
                    lowNos = []

                    while lowp < highp:
                        if nums[lowp] + nums[highp] == 0 - nums[i]:
                            if nums[lowp] not in lowNos:
                                lowNos.append(nums[lowp])
                                tmp = [nums[i], nums[lowp], nums[highp]]
                                res.append(tmp)

                            lowp += 1
                            continue

                        if nums[lowp] + nums[highp] < 0 - nums[i]:
                            lowp += 1
                            continue

                        if nums[lowp] + nums[highp] > 0 - nums[i]:
                            highp -= 1

        return res
```