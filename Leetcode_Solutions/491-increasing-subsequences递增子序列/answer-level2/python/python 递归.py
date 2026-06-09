基本思路：
将列表拆分成（1->n-1） (n)两组。结果集包含以下几个部分：
1、第一组的结果集合
2、第一组每个独立元素如果小于等于n，则组成列表插入结果集合
3、第一组的结果集合的每个列表的最后一个元素如果小于等于n，则与n组成的新的列表插入结果集合

每次将新的列表加入集合的时候判断需要判断是否重合。

按照这个思路，这个题就可以解了。
class Solution(object):
    def findSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n = len(nums)
        res = []
        if n == 1:
            return res
        if n == 2:
            if nums[0] <= nums[1]:
                res = [nums]
            return res
        subnums = nums[:-1]
        lastnum = nums[-1]
        res = self.findSubsequences(subnums)
        for i in range(len(res)):
            if res[i][-1] <= lastnum:
                import copy
                newRecord = copy.copy(res[i])
                newRecord.append(lastnum)
                if newRecord not in res:
                    res.append(newRecord)
        for i in range(len(subnums)):
            if subnums[i] <= lastnum and [subnums[i],lastnum] not in res:
                res.append([subnums[i],lastnum])
        return res
