做这道题目之前，我们先来了解一下字典序的概念：
    在数学中，字典或词典顺序（也称为词汇顺序，字典顺序，
    字母顺序或词典顺序）是基于字母顺序排列的单词按字母顺序排列的方法。 
    这种泛化主要在于定义有序完全有序集合（通常称为字母表）的元素的序列
   （通常称为计算机科学中的单词）的总顺序。
通俗的讲就是：
    比如13254和13425这两个排列，从左到右依次比较数字，
    到第三个数字的时候有：2<4，所以排列13425在排列13254的后面
    而下一个排列的意思是在排序13254的后面比它大的最小排列

算法步骤：
    （1）从最右端开始找出第一个比右边数字小的数字的序号loc，如果没有找到这样的loc，则将nums升序排列
    （2）在loc的右端找到比nums[cur]大的最小的数字的序号cur
    （3）交换loc和cur位置上的元素
     (4) 将loc+1:len(nums)之间的元素倒置

1. class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # 从最右端开始找出第一个比右边数字小的数字的序号loc
        loc = -1
        for i in range(len(nums)-2, -1, -1):
            if nums[i] < nums[i+1]:
                loc = i
                break
        # 如果没有找到这样的loc，则将nums升序排列
        if loc == -1:
            nums.sort()
            return
        # 在loc的右端找到比nums[cur]大的最小的数字的序号cur
        cur = loc+1
        if loc + 2 < len(nums):
            for i in range(loc + 2, len(nums)):
                if nums[cur] >= nums[i] and nums[i] > nums[loc]:
                    cur = i
        # 交换loc和cur位置上的元素
        nums[loc], nums[cur] = nums[cur], nums[loc]
        # 将loc+1:len(nums)之间的元素倒置
        nums[loc+1:len(nums)] = nums[len(nums)-1:loc:-1]


