# 思路
1. 如果只有list只有一个element，就返回此element。
2. 每次while循环找出相邻两个elements的共同prefix。
3. 每次for循环执行找出共同prefix的过程。
3. 如果elements的长度不一，或者干脆某element是""，导致index out of range，就结束算法，返回目前叠加的pre。

# 算法
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 1:
        # 如果只有list只有一个element，就返回此element
            return strs[0]
        j = 0
        pre = ""
        while (j+1):
            try:
            # 找出相邻两个elements的共同prefix
                for i in range(len(strs) - 1):
                    if strs[i][j] != strs[i+1][j]:
                        j = -2  # 当任意相邻两个字符串的任意同位置字符不同，（-2 + 1 + 1 = 0）所以while loop结束
                        break
                if j >= 0:
                    pre += strs[1][j]
                j += 1
            except:
            # 如果elements的长度不一，或者干脆某element是""，导致index out of range，就结束算法，返回目前叠加的pre
                return pre
        return pre

# 复杂度解析
- 时间复杂度：O(S), 其中S为所有字符串中所有字符量的总和。
- 空间复杂度：O(1), 仅3个变量。