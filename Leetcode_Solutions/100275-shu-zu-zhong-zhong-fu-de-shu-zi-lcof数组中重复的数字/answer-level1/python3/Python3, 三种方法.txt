```
#思路1
#先把输入的数组排序，再从头到尾扫描排序后的数组，如果相邻的两个元素相等，则存在重复数字。
#时间复杂度: O(nlogn)
#空间复杂度: O(n)

from typing import  List
class Solution:
    
    def duplicate(self, nums: List[int]) -> int:
        nums = sorted(nums)   #sorted() 采用了Timesort算法  ,时间复杂度为 O(nlogn)
        #排序后,遍历
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                return nums[i]
        return -1


#思路2
#利用哈希表来解决。从头到尾扫描数组的每个元素，
# 每扫描到一个元素，都可以用O(1)的时间来判断哈希表中是否已经存在该数字，
# 如果存在，说明找到了重复元素，
# 如果不存在，则将其加入到哈希表中。时间复杂度O(n)，空间复杂度O(n)。
class Solution2:

    def duplicate(self, nums: List[int]) -> int:
        hash = {}
        # 排序后,遍历
        for item in nums:
            if item in hash:
                return item
            else:
                hash[item] = 0
        return -1

#思路3
#由于数组中元素都在0~n - 1的范围内，
# 如果这个数组中没有重复元素，那么当数组排序后，数字i将会处于i的位置。
# 从头到尾依次扫描数组中的元素，
# 当扫描第i个元素时，如果这个元素是i，则继续扫描下一个元素，
# 如果不是i，而是m，则将其与第m个元素比较，如果两者相等，则找到了重复的数字，
# 如果不相等，则将二者交换位置，重复该过程，直到找到重复元素。时间复杂度O(n)，空间复杂度O(1).

class Solution3:
    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicate(self, nums: List[int]) -> int:
        # write code here
        for i in range(len(nums)):
            while nums[i] != i:
                if nums[nums[i]] == nums[i]:
                    return nums[i]

                else:
                    nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
        return -1
```
