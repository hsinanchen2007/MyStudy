# 题目要求 O(n) 复杂度。

# - 用哈希表存储每个端点值对应连续区间的长度
# - 若数已在哈希表中：跳过不做处理
# - 若是新数加入：
#     - 取出其左右相邻数已有的连续区间长度 left 和 right
#     - 计算当前数的区间长度为：`cur_length = left + right + 1`
#     - 根据 cur_length 更新最大长度 max_length 的值
#     - 更新区间两端点的长度值

# ```python
class Solution(object):
    def longestConsecutive(self, nums):
        hash_dict = dict()
        
        max_length = 0
        for num in nums:
            if num not in hash_dict:
                left = hash_dict.get(num - 1, 0)
                right = hash_dict.get(num + 1, 0)
                
                cur_length = 1 + left + right
                if cur_length > max_length:
                    max_length = cur_length
                
                hash_dict[num] = cur_length
                hash_dict[num - left] = cur_length
                hash_dict[num + right] = cur_length
                
        return max_length
# ```

# ----

# ## 🐱

# - 我的题解项目: [GitHub - leetcode-notebook](https://github.com/JalanJiang/leetcode-notebook)
# - 如果你对做题和分享题解感兴趣，欢迎加入 [LeetCode 刷题小分队](https://github.com/leetcode-notebook/leetcode-notebook.github.io/blob/master/README.md)
# - 如果你觉得题解写得不错，欢迎关注公众号「编程拯救世界」，公众号专注于编程基础与服务端研发，定期分享算法与数据结构干货~

# ![](https://pic.leetcode-cn.com/19e1d10a6d54a3e362ba5b7ad024a689720b30848e7e7b9e3ca971eae5ebd7b6-file_1574392293896)
