#
# @lc app=leetcode.cn id=1186 lang=python
#
# [1186] 删除一次得到子数组最大和
#

# @lc code=start
class Solution(object):
    def maximumSum(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        len_a = len(arr)
        a = [0] * (len(arr) + 1)
        b = [0] * (len(arr) + 1)
        rst = arr[0]
        all_min_flag = True 
        max_min = -float('inf')
        for i in range(len_a):
            if arr[i] >=0:
                all_min_flag = False 
            max_min = max(max_min, arr[i])
            a[i+1] = max(a[i]+arr[i], b[i], 0)  # 前面已经删除过个元素了，或者删除当前的元素，此时的两种情况都是使用了前面的序列, 最后一种情况是既不使用前面的序列也不使用当前的元素
            b[i+1] = max(b[i]+arr[i], arr[i])   # 加以前的元素，或者不加以前的元素
            rst = max(rst,  a[i+1], b[i+1])
        if all_min_flag:
            rst = max_min
        return rst
# @lc code=end

