
# 我们维护上下左右四个边界。  我们的遍历方向有四个：

# - 向右👉：到达边界之后，我们更新右边界 - 1
# - 向下👇：到达边界之后，我们更新下边界 - 1
# - 向左👈：到达边界之后，我们更新左边界 + 1
# - 向上👆：到达边界之后，我们更新上边界 + 1

# 当四个边界重叠了，我们退出循环。

# ```python
#
# @lc app=leetcode.cn id=54 lang=python3
#
# [54] 螺旋矩阵
#

# @lc code=start


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        top = 0
        bottom = len(matrix) - 1
        if bottom < 0:
            return res
        left = 0
        right = len(matrix[0]) - 1

        while left <= right and top <= bottom:
            j = left
            while j <= right:
                res.append(matrix[top][j])
                j += 1
            top += 1

            i = top
            if i > bottom:
                break
            while i <= bottom:          
                res.append(matrix[i][right])
                i += 1
            right -= 1

            j = right
            if j < left:
                break
            while j >= left:
                res.append(matrix[bottom][j])
                j -= 1
            bottom -= 1

            i = bottom
            if i < top:
                break
            while i >= top:
                res.append(matrix[i][left])
                i -= 1
            left += 1

        return res


# @lc code=end
# ```


# 欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

# ![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
