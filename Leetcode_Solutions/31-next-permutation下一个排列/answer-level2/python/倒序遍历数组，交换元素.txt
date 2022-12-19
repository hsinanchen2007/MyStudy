思路：
    从右侧倒序遍历数组，找到第一对连续的nums[i]和nums[i-1]使得nums[i] > nums[i-1]。（因为如果希望数字变大，需要将更大的数放到更小的数之前）。
    此时，nums[i:]中的所有数字按照降序排列。因此将问题简化为重排nums[i-1:]，使重排后的数字为原数字字典序的下一位，且nums[i:]为降序的。
    为了使替换后的数字满足要求，首先需要将nums[i-1]替换为nums[i:]大于该位置元素且于其最接近的nums[j]。
    因此，遍历nums[i:]，找到更大的且与其最接近的nums[j]，交换nums[i-1]和nums[j]。
    交换后nums[i:]依旧是降序，因此仍不符合字典序的要求，需要将其reverse为升序，即为要求的字典序中的下一位。
```
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        idx = -1
        for i in range(length-1, 0, -1):
            # 倒序遍历数组，查找第一个，比后一个数字小的元素索引
            if nums[i] > nums[i-1]:
                idx = i - 1
                break
            # 否则idx = None，说明数组是降序数组，不存在比后一个数小的元素
        if idx == -1:
            return nums.sort()
        # 若数组不是降序数组，则在nums[idx + 1: ]中查找大于nums[idx]且最接近nums[idx]的数与其交换
        minidx = float('inf')
        for i in range(idx + 1, length):
            if nums[i] > nums[idx] and nums[i] < minidx:
                newidx = i
        tmp = nums[newidx]
        nums[newidx] = nums[idx]
        nums[idx] = tmp
        # 交换后，重新排序第i到最后
        nums[idx + 1:] = sorted(nums[idx + 1:])
        
        return nums
```
