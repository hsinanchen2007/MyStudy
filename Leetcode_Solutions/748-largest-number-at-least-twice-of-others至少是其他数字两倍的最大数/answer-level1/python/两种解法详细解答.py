# ### 解一：常规做法

# 常规做法：

# 1. 先遍历数组找出最大数
# 2. 二次遍历数组判断最大数是否为其他数字的至少两倍大

# ```python
class Solution(object):
    def dominantIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_num = nums[0]
        max_index = 0
        
        # 找出最大数
        for i in range(len(nums)):
            if nums[i] > max_num:
                max_num = nums[i]
                max_index = i
        
        # 判断最大数是否至少是其他元素的两倍
        for i in range(len(nums)):
            if i != max_index and nums[i] * 2 > max_num:
                return -1
        
        return max_index
# ```

# ### 解二：判断最大数是否为第二大数的两倍

# 如果最大数必须是所有元素的至少两倍大，那么最大数一定是第二大数的至少两倍大。因此：

# 1. 循环数组找出最大数和第二大数
# 2. 比较两者大小

# ```python
class Solution(object):
    def dominantIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_num = float('-inf')
        max_index = 0
        second_max_num = float('-inf')
        
        # 找出最大数和第二大数
        for i in range(len(nums)):
            n = nums[i]
            if n > max_num:
                second_max_num = max_num
                max_num = n
                max_index = i
            else:
                if n > second_max_num:
                    second_max_num = n
        
        if max_num >= second_max_num * 2:
            return max_index
        else:
            return -1
# ```

# ----

# ## 🐱

# - 我的题解项目: [GitHub - leetcode-notebook](https://github.com/JalanJiang/leetcode-notebook)
# - 如果你对做题和分享题解感兴趣，欢迎加入 [LeetCode 刷题小分队](https://github.com/leetcode-notebook/leetcode-notebook.github.io/blob/master/README.md)
# - 如果你觉得题解写得不错，欢迎关注公众号「编程拯救世界」，公众号专注于编程基础与服务端研发，定期分享算法与数据结构干货~

# ![](https://pic.leetcode-cn.com/19e1d10a6d54a3e362ba5b7ad024a689720b30848e7e7b9e3ca971eae5ebd7b6-file_1574392293896)