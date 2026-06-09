这方法都是靠测试用例试出来的
1.排序
2.根据去重set和去掉0后的list的数据量做比较，去掉因数据重复导致不能成顺子的情况
3.将除0以外的数据求相邻差值和list的长度作比较
```
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        if not nums:
            return False
        count = 0
        sub = 0
        nums = sorted(nums)
        for i in range(len(nums)):
            if nums[i] == 0:
                count += 1
        length = len(nums) - count
        M = nums[count:]
        if len(set(M)) != length :
            return False
        else:
            for i in range(length-1):
                sub += M[i+1]-M[i]
            if sub < length:
                return True
            elif sub - count < length:
                return True
            else:
                return False
```
