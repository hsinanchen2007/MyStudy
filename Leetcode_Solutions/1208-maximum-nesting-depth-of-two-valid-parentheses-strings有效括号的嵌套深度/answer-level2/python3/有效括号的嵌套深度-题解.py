# ### 解题思路

# 题目确实没读懂，只好请教官方题解跟各位大佬的辅助解答了。
# - [官方题解](https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/solution/you-xiao-gua-hao-de-qian-tao-shen-du-by-leetcode-s/)
# - [Sweetiee 🍬](https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/solution/ti-mian-shuo-ming-ti-mu-jiang-jie-shuo-hao-fa-wan-/)
# - [Dou](https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/solution/ti-mu-de-yi-si-shi-by-dou-4/)

# 感谢感谢

# ### 代码

# ```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:

        nums = len(seq)
        stack = []
        for i in range(nums):
            if seq[i] == '(':
                stack.append(i%2)
            else:
                stack.append((i+1)%2)
        
        return stack
# ```