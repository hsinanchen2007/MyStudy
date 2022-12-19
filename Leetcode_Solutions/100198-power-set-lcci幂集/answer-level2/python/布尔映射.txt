class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        list=[]
        length=len(nums)
        test_marks = [1 << i for i in range(0,length)]
        for k in range(2**length):
            l=[]
            for idx, item in enumerate(test_marks):
                if k&item:
                    l.append(nums[idx])
            list.append(l)
        return list

将每个子集映射成二进制数，第i位可以表示元素是否在集合中的“布尔”标志。