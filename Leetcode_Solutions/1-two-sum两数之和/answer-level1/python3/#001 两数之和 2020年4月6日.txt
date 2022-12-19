### 解题思路
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

1.首先的思路还是使用两层循环暴力解决……
2.使用哈希表

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 两层循环（双指针）
        """
        lens = len(nums)
        for i in range(lens):
            for j in range (i+1,lens):
                if nums[i] + nums[j] == target:
                    return [i, j]
        """
        # 哈希表
        lens = len(nums)
        dict1 = {}
        for i in range(lens):
            k = target - nums[i]
            if k in dict1:
                return [dict1[k], i]
            dict1[nums[i]] = i

```