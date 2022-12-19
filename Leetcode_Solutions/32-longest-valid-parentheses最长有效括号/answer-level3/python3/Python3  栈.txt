```
#
# @lc app=leetcode.cn id=32 lang=python
#
# [32] 最长有效括号
#

# @lc code=start
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = [-1]  # -1是0 前面位置的下标
        # for i in range(len(s)):
        rst = 0
        for idx, char in enumerate(s):
            if char == '(':
                stack.append(idx)
            else:
                stack.pop(-1)
                if len(stack) == 0:  #  如果连-1也pop出去了  ())这种情况就将 -1 pop出去了，然后 )的下标就是这次的坐标下界，最下面的-1是用来兜底的值，核心是所有的(都pop出来了，然后还来了一个)那么肯定是不匹配的，当前兜底的值换成)的下标，如果里面还有(那么还可能连成一串，所以不用换兜底的
                    stack.append(idx)
                else:
                    rst = max(rst, idx - stack[-1])
        return rst


```
