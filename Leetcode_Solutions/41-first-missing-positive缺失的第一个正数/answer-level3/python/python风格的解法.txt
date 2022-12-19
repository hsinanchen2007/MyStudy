一个比较python风格的方法：
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        dicts = dict(zip(nums,nums))
        for i in range(1,len(nums)+2):
            if i not in dicts:
                return i
用字典，字典判断in的复杂度是O(1)，只要遍历一次即可
