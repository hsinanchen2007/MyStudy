


```py
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # 第一种方法：这里需要返回的是最大值，所以需要　使用最大堆 实现。
        # 时间复杂度　为　O(Nlogk)，最大堆替换掉元素是Ｏ(logk)

        # 第二种方法：使用双端队列实现：　时间复杂度是:Ｏ(N)
        #　题目的特点是　　只需要找到最大的那个数即可，始终让滑动窗口的最左端　存储最小的数据
        # 双端队列：　两端都可以添加和删除　window

        if not nums: return []  # 

        window, res = [], []
        # window 中存放的是　三个窗口的数据的下标
        # window 就是双端队列　队列的右侧是０，左侧是-1,即用window[0]存放三个窗口中最右侧的那个数的索引。用window[-1]存放三个窗口中最左侧的那个数的索引。
        # python 中　用列表就能　实现双端队列
        # .pop(0) 是删除队列，列表左侧的数据
        # .pop() 是删除队列，列表右侧的数据
        # .append() 是在右侧添加　元素

        for i, x in enumerate(nums):  # 遍历列表中的每一个元素
            #　当　滑动窗口　滑到中间还没有出去，即窗口中的元素维持在三个的时候；            
            if i >= k and window[0] <= i-k:  
                window.pop(0)  # （删除左侧的下标）从队列# 强行将窗口中　最左侧的下标　移除；
            # nums[window[-1]] 窗口中的


            while window and nums[window[-1]] <= x:  # 新来的数x大于　之前最大的数
                window.pop()  # 清空之前所有的　下标
            window.append(i)  # （添加右侧的下标）新来的下标是一定还要　添加进去的。
            if i>=k-1:
                res.append(nums[window[0]])  
                # window 中最左侧存放的永远是，最大的那个数的下标。
        return res





```
