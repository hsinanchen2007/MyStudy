我的思路其实是最直观的，第一遍遍历nums数组的时候，如果遍历到下标是a的值，那就继续遍历a到剩下的数组
如果遍历到下标是b的值，那就继续遍历b到剩下的值，然后把三次遍历的值加起来算总和是不是0，是就放到结果列表里，放之前记得去重
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        for a in range(len(nums)):
            rest1 = nums[a+1:]
            for b in range(len(rest1)):
                rest2 = rest1[b+1:]
                for c in range(len(rest2)):
                    sum = nums[a] + rest1[b] + rest2[c]
                    tmp_list = []
                    if sum == 0:
                        tmp_list.append(nums[a])
                        tmp_list.append(rest1[b])
                        tmp_list.append(rest2[c])
                        if self.isDuplicated(result, tmp_list) == False:
                            result.append(tmp_list)
        return result
    
    def isDuplicated(self, result, tmp_list):
        for num in result:
            if set(num) == set(tmp_list):
                return True
        return False