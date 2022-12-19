```
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        m = 0
        dp = [0] * len(s)
        dp[0] = -1  # 存放每一个位置匹配上之后下一个待匹配的括号的位置
        wanted = 0
        for i, c in enumerate(s):
            if i != 0:
                dp[i] = wanted  # 更新在当前这个位置匹配时，下一个要匹配的括号
            if c == "(":
                wanted = i  # 如果是左括号，接下来一定要匹配这个括号
            else:
                if s[wanted] == ")":  # 如果待匹配的位置是右括号，说明上次匹配已经匹配了最大长度，可以重新开始匹配了
                    wanted = i
                    continue
                if wanted == -1:  # 如果wanted为-1, 表示上一次的已经匹配完了从0开始的字符串，这里从当前位置开始即可
                    wanted = i
                    continue
                wanted = dp[wanted]  # 如果c是右括号，且待匹配的是一个左括号，匹配他，并且找下一个待匹配的位置
                new_m = i - wanted
                m = max(m, new_m)
        return m

```
