由于ops的每个操作`a 的范围是 [1,m]，b 的范围是 [1,n]`, 则每次操作必定有数字会增加1, 则求这些操作的涉及的面积的交集就好了;

所以求所以a的最小值, 和b的最小值, 得到的面积就是含有最大整数的元素个数

```
#
# @lc app=leetcode.cn id=598 lang=python
#
# [598] 范围求和 II
#
# https://leetcode-cn.com/problems/range-addition-ii/description/
#
# algorithms
# Easy (47.39%)
# Likes:    18
# Dislikes: 0
# Total Accepted:    2.4K
# Total Submissions: 5K
# Testcase Example:  '3\n3\n[[2,2],[3,3]]'
#
# 给定一个初始元素全部为 0，大小为 m*n 的矩阵 M 以及在 M 上的一系列更新操作。
#
# 操作用二维数组表示，其中的每个操作用一个含有两个正整数 a 和 b 的数组表示，含义是将所有符合 0 <= i < a 以及 0 <= j < b 的元素
# M[i][j] 的值都增加 1。
#
# 在执行给定的一系列操作后，你需要返回矩阵中含有最大整数的元素个数。
#
# 示例 1:
#
#
# 输入:
# m = 3, n = 3
# operations = [[2,2],[3,3]]
# 输出: 4
# 解释:
# 初始状态, M =
# [[0, 0, 0],
# ⁠[0, 0, 0],
# ⁠[0, 0, 0]]
#
# 执行完操作 [2,2] 后, M =
# [[1, 1, 0],
# ⁠[1, 1, 0],
# ⁠[0, 0, 0]]
#
# 执行完操作 [3,3] 后, M =
# [[2, 2, 1],
# ⁠[2, 2, 1],
# ⁠[1, 1, 1]]
#
# M 中最大的整数是 2, 而且 M 中有4个值为2的元素。因此返回 4。
#
#
# 注意:
#
#
# m 和 n 的范围是 [1,40000]。
# a 的范围是 [1,m]，b 的范围是 [1,n]。
# 操作数目不超过 10000。
#
#
#
class Solution(object):
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        if not ops:
            return m * n
        return min(i[0] for i in ops) * min(i[1] for i in ops)


```